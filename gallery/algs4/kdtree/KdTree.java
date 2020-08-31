import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;

public class KdTree{
    private Node root;
    private int size;

    private static class Node{
        private Point2D p;
        private RectHV rect;
        private Node leftOrBottom;
        private Node rightOrTop;
        private boolean isEvenLevel;

        public Node(Point2D p,RectHV rect,boolean isEvenLevel){
            this.p = p;
            this.rect = rect;
            this.isEvenLevel = isEvenLevel;
        }
    }

    public KdTree(){}

    public boolean isEmpty(){
        return size == 0;
    }

    public int size(){
        return size;
    }

    public void insert(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        root = insert(root,null,p,0);//这里的0换成大于0或小于的0的值应该都可以
    }

    private Node insert(Node curNode,Node parent,Point2D p,int direction){
        if(curNode == null){ //leaf node
            if(size++ == 0)
                return new Node(p,new RectHV(0,0,1,1),true);

            RectHV rectOfcurNode = parent.rect;
            /*
            如果没有 = parent.rect 错误:
            可能尚未初始化变量rectOfcurNode
            return new Node(p,rectOfcurNode,!parent.isEvenLevel);
            */
            if(direction < 0){ //go left sub-tree 这里是按Kd树来分的。不是按划分区域
                //以下是按划分区域来分的
                if(parent.isEvenLevel) //left sub-rectangle (divided by x)
                    rectOfcurNode = new RectHV(parent.rect.xmin(),parent.rect.ymin(),
                                               parent.p.x(),parent.rect.ymax());
                else //bottom sub-rectangle (divided by y)
                    rectOfcurNode = new RectHV(parent.rect.xmin(),parent.rect.ymin(),
                                               parent.rect.xmax(),parent.p.y());
            }
            else if(direction > 0){ //go right sub-tree
                if(parent.isEvenLevel){ //right sub-rectangle (divided by x)
                    rectOfcurNode = new RectHV(parent.p.x(),parent.rect.ymin(),
                                               parent.rect.xmax(),parent.rect.ymax());
                }
                else //top sub-rectangle (divided by y)
                    rectOfcurNode = new RectHV(parent.rect.xmin(),parent.p.y(),
                                               parent.rect.xmax(),parent.rect.ymax());
            }

            return new Node(p,rectOfcurNode,!parent.isEvenLevel);
        }

        int cmp = compare(p, curNode.p, curNode.isEvenLevel);
        //选择Kd树的左子树还是右子树
        if(cmp < 0) curNode.leftOrBottom = insert(curNode.leftOrBottom,curNode,p,cmp);
        else if(cmp > 0) curNode.rightOrTop = insert(curNode.rightOrTop,curNode,p,cmp);
        //duplicate point 不插入

        return curNode;

    }
    //isEvenLevel ---> red;!isEvenLevel ---> black
    private int compare(Point2D p,Point2D q,boolean isEvenLevel){
        if(p == null || q == null) throw new IllegalArgumentException();
        if(p.equals(q)) return 0;
        if(isEvenLevel) return p.x() < q.x() ? -1 : 1;
        else  return p.y() < q.y() ? -1 : 1;
        //大于等于0 插入右子树
    }

    public boolean contains(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        return contains(root,p);
    }

    private boolean contains(Node node,Point2D p){
        if(node == null) return false;
        int cmp = compare(p, node.p, node.isEvenLevel);

        if(cmp<0) return contains(node.leftOrBottom,p);
        else if(cmp>0) return contains(node.rightOrTop,p);
        else return true;
    }

    public void draw(){
        draw(root);
    }

    private void draw(Node node){
        if(node == null) return;
        draw(node.leftOrBottom);
        draw(node.rightOrTop);
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.01);
        node.p.draw();
        StdDraw.setPenRadius();
        StdDraw.show();
        StdDraw.pause(5000);
        if(node.isEvenLevel){ // x
            StdDraw.setPenColor(StdDraw.RED);
            StdDraw.line(node.p.x(),node.rect.ymin(),node.p.x(),node.rect.ymax());
        }
        else{ // y
            StdDraw.setPenColor(StdDraw.BLUE);
            StdDraw.line(node.rect.xmin(),node.p.y(),node.rect.xmax(),node.p.y());
        }
    }

    public Iterable<Point2D> range(RectHV rect){
        if(rect == null) throw new IllegalArgumentException();
        Queue<Point2D> pointQueue = new Queue<Point2D>();

        range(root,pointQueue,rect);
        return pointQueue;//Iterable
    }
    private void range(Node node,Queue<Point2D> pointQueue,RectHV rect){
        if(node == null) return;
        if(rect.contains(node.p)) pointQueue.enqueue(node.p);

        // if the left sub-rectangle intersects rect, then search the left-tree
        if(node.leftOrBottom != null && rect.intersects(node.leftOrBottom.rect)) range(node.leftOrBottom,pointQueue,rect);
        // if ...
        if(node.rightOrTop != null && rect.intersects(node.rightOrTop.rect))    range(node.rightOrTop,pointQueue,rect);
    }

    public  Point2D nearest(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        if(root == null) return null;
        return nearest(root,root.p,p);
    }

    private Point2D nearest(Node node,Point2D curNearest,Point2D p){
        if(node == null) return curNearest; //leaf node

        int cmp = compare(p, node.p, node.isEvenLevel);

        if(p.distanceSquaredTo(node.p) < p.distanceSquaredTo(curNearest)) curNearest = node.p;

        if(cmp < 0){ //左子树
            curNearest = nearest(node.leftOrBottom,curNearest,p);
            if(node.rightOrTop != null){
                if(curNearest.distanceSquaredTo(p) > node.rightOrTop.rect.distanceSquaredTo(p))
                    curNearest = nearest(node.rightOrTop,curNearest,p);
            }
        }
        else if(cmp > 0){ //右子树
            curNearest = nearest(node.rightOrTop,curNearest,p);
            if(node.leftOrBottom != null){
                if(curNearest.distanceSquaredTo(p) > node.leftOrBottom.rect.distanceSquaredTo(p))
                    curNearest = nearest(node.leftOrBottom,curNearest,p);
            }
        }
        return curNearest;
    }

    public static void main(String[] args){
        double timeOfInsert = 0.0;
        double timeOfNearest = 0;
        double timeOfRange = 0;
        KdTree kdtree = new KdTree();
        Stopwatch timer;
        Point2D p;
        for(int i =0;i<1000000;i++){
            p = new Point2D(StdRandom.uniform(0.0,1.0),StdRandom.uniform(0.0,1.0));
            timer = new Stopwatch();
            kdtree.insert(p);
            timeOfInsert += timer.elapsedTime();
        }

        StdOut.print("time cost of insert(random point)(10^6 times)  :");
        StdOut.println(timeOfInsert);

        for(int i =0;i<100;i++){
            p = new Point2D(StdRandom.uniform(0.0,1.0),StdRandom.uniform(0.0,1.0));
            timer = new Stopwatch();
            kdtree.nearest(p);
            timeOfNearest += timer.elapsedTime();
        }
        StdOut.print("time cost of nearest(random point)(100 times)  :");
        StdOut.println(timeOfNearest);

        for(int i = 0;i<100;i++){
            double xmin = StdRandom.uniform(0.0,1.0);
            double ymin = StdRandom.uniform(0.0,1.0);
            double xmax = StdRandom.uniform(0.0,1.0);
            double ymax = StdRandom.uniform(0.0,1.0);
            if(xmin>xmax){
                double tmp = xmin;
                xmin = xmax;
                xmax = tmp;
            }
            if(ymin>ymax){
                double tmp = ymin;
                ymin = ymax;
                ymax = tmp;
            }
            RectHV rect = new RectHV(xmin,ymin,xmax,ymax);
            timer = new Stopwatch();
            kdtree.range(rect);
            timeOfRange += timer.elapsedTime();
        }
        StdOut.print("time cost of range(random rectangle)(100 times)  :");
        StdOut.println(timeOfRange);

        KdTree kdtree_draw = new KdTree();
        for(int i =0;i<20;i++){
            p = new Point2D(StdRandom.uniform(0.0,1.0),StdRandom.uniform(0.0,1.0));
            kdtree_draw.insert(p);
        }
        kdtree_draw.draw();
    }
}

import edu.princeton.cs.algs4.Point2D;
import edu.princeton.cs.algs4.Queue;
import edu.princeton.cs.algs4.RectHV;
import edu.princeton.cs.algs4.SET;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.Stopwatch;

public class PointSET{
    private SET<Point2D> points;

    public PointSET(){
        points = new SET<Point2D>();
    }

    public boolean isEmpty(){
        return points.isEmpty();
    }

    public int size(){
        return points.size();
    }

    public void insert(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        points.add(p);
    }

    public boolean contains(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        return points.contains(p);
    }

    public void draw(){
        StdDraw.setPenColor(StdDraw.BLACK);
        StdDraw.setPenRadius(0.01);
        for(Point2D point : points){
            point.draw();
        }
    }

    public Iterable<Point2D> range(RectHV rect){
        if(rect == null) throw new IllegalArgumentException();

        Queue<Point2D> pointsInRect = new Queue<Point2D>();
        for(Point2D point : points){
            if(rect.contains(point)) pointsInRect.enqueue(point);
        }

        return pointsInRect;
    }

    public Point2D nearest(Point2D p){
        if(p == null) throw new IllegalArgumentException();
        if(points.isEmpty()) return null;

        Point2D nearestPoint = points.min();
        double minDist = Double.POSITIVE_INFINITY;
        for(Point2D point : points){
            double dist = p.distanceSquaredTo(point);
            if(minDist>dist){
                nearestPoint = point;
                minDist = dist;
            }
        }

        return nearestPoint;
    }

    public static void main(String[] args){
        double timeOfInsert = 0.0;
        double timeOfNearest = 0;
        double timeOfRange = 0;
        PointSET brute = new PointSET();
        Stopwatch timer;
        Point2D p;

        for(int i =0;i<1000000;i++){
            p = new Point2D(StdRandom.uniform(0.0,1.0),
                            StdRandom.uniform(0.0,1.0));
            timer = new Stopwatch();
            brute.insert(p);
            timeOfInsert += timer.elapsedTime();
        }

        StdOut.print("time cost of insert(random point)(10^6 times)  :");
        //StdOut.println(timeOfInsert+"s"); 这样写会导致时间不准确，因为字符串拼接是O(n)
        StdOut.println(timeOfInsert);

        for(int i = 0;i<100;i++){
            p = new Point2D(StdRandom.uniform(0.0,1.0),
                            StdRandom.uniform(0.0,1.0));
            timer = new Stopwatch();
            brute.nearest(p);
            timeOfNearest += timer.elapsedTime();
        }
        StdOut.print("time cost of nearest(random point)(100 times)  :");
        StdOut.println(timeOfNearest);

        for(int i = 0;i<100;i++){
            double xmin = StdRandom.uniform(0.0,1.0);
            double ymin = StdRandom.uniform(0.0,1.0);
            double xmax = StdRandom.uniform(0.0,1.0);
            double ymax = StdRandom.uniform(0.0,1.0);
            RectHV rect;
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

            rect = new RectHV(xmin,ymin,xmax,ymax);
            timer = new Stopwatch();
            brute.range(rect);
            timeOfRange += timer.elapsedTime();
        }
        StdOut.print("time cost of range(random rectangle)(100 times)  :");
        StdOut.println(timeOfRange);
    }
}

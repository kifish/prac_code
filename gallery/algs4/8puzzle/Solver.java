import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

public class Solver{
    private SearchNode current;
    private boolean isSolvable;

    private class SearchNode implements Comparable<SearchNode>{
        private Board bd;
        private SearchNode pre;
        private int moves;
        private int priority;
        private boolean isInitParity;
        public SearchNode(Board bd,boolean isInitParity){
            if(bd == null) throw new IllegalArgumentException();
            this.bd = bd;
            this.moves = 0;
            this.priority = this.bd.manhattan() + this.moves;
            this.isInitParity = isInitParity;
        }
        public SearchNode(Board bd,SearchNode pre){
            if(bd == null) throw new IllegalArgumentException();
            if(pre == null) throw new IllegalArgumentException();
            this.bd = bd;
            this.pre = pre;
            this.moves = pre.moves +1;
            this.priority = this.bd.manhattan() + this.moves;
            this.isInitParity = pre.isInitParity;
        }

        public int compareTo(SearchNode that){
            //priA < priB or mA < mB(priA == priB)
            if(this.priority == that.priority)  return this.bd.manhattan() - that.bd.manhattan();
            else return this.priority -that.priority;
        }
    }

    public Solver(Board initial){
        if(initial == null) throw new IllegalArgumentException();
        MinPQ<SearchNode> oriPQ = new MinPQ<SearchNode>();

        oriPQ.insert(new SearchNode(initial,true));//two states
        oriPQ.insert(new SearchNode(initial.twin(),false));
        while(true){
            current = oriPQ.delMin();
            if(current.bd.isGoal()) break;
            for(Board nb : current.bd.neighbors()){
                if(current.pre == null || !nb.equals(current.pre.bd)){
                    oriPQ.insert(new SearchNode(nb,current));
                }
            }
        }
        isSolvable = current.isInitParity;
    }
    public boolean isSolvable(){
        return this.isSolvable;
    }

    public int moves(){
        if(!isSolvable()) return -1;
        else return current.moves;
    }

    public Iterable<Board> solution(){
        if(!isSolvable()) return null;
        Stack<Board> boards = new Stack<Board>();
        SearchNode node = current;// reference
        while(node != null){
            boards.push(node.bd);
            node = node.pre;
        }
        return boards;
    }

    public static void main(String[] args){
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] blocks = new int [n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                blocks[i][j] = in.readInt();
        }

        Board initial = new Board(blocks);

        Solver solver = new Solver(initial);
        if(!solver.isSolvable())
            StdOut.println("No solution possible");
        else{
            StdOut.println("Minimum number of moves = " + solver.moves());
            for(Board board : solver.solution())
                StdOut.println(board);
        }
    }
}

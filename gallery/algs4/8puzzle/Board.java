import java.util.Arrays;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Stack;
import edu.princeton.cs.algs4.StdOut;

public class Board{
    private int n;
    private int[] blocks1D;

    public Board(int[][] blocks){
        if(blocks == null) throw new IllegalArgumentException();
        n = blocks.length;
        this.blocks1D = new int[n*n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++)
                this.blocks1D[i*n+j] = blocks[i][j];
        }
    }

    private Board(int[] blocks){
        if(blocks == null) throw new IllegalArgumentException();
        n = (int)Math.sqrt(blocks.length);
        this.blocks1D = Arrays.copyOf(blocks,blocks.length);
    }
    public int dimension(){
        return n;
    }
    public int hamming(){
        int hammingSum = 0;
        for(int i = 0;i<blocks1D.length;i++){
            if(blocks1D[i] != 0){
                if(blocks1D[i] != i+1)
                    hammingSum++;
            }
        }
        return hammingSum;
    }
    public int manhattan(){
        int manhattanSum = 0;
        int rightRow;
        int rightCol;
        int row;
        int col;
        for(int i = 0;i<blocks1D.length;i++){
            if(blocks1D[i] != 0&&blocks1D[i] != i+1){
                rightRow = (blocks1D[i]-1)/n;
                rightCol = blocks1D[i]-1-rightRow*n;
                row = i/n;
                col = i - row*n;
                manhattanSum += Math.abs(rightRow-row)+Math.abs(rightCol-col);
            }
        }
        return manhattanSum;
    }
    public boolean isGoal(){
        return this.manhattan()==0;
    }
    public Board twin(){
        int[] twinBlocks;
        if(blocks1D[0] != 0 && blocks1D[1] != 0){
            twinBlocks = getSwappedBlocks(0,1);
        }
        else{
            twinBlocks = getSwappedBlocks(n*n-2,n*n-1);
        }
        return new Board(twinBlocks);
    }
    public boolean equals(Object y){
        if(y == this) return true;
        if(y == null) return false;
        if(y.getClass() != this.getClass()) return false;

        Board that = (Board) y;
        if(this.dimension() != that.dimension()) return false;
        return Arrays.equals(this.blocks1D,that.blocks1D);
    }
    public Iterable<Board> neighbors(){
        Stack<Board> neighbors = new Stack<Board>();
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        int blankRow;
        int blankCol;
        int[] swappedBlocks;
        int blankIdx;
        int neighborIdx;
        for(blankIdx = 0;blankIdx<blocks1D.length;blankIdx++){
            if(blocks1D[blankIdx] == 0) break;
        }
        for(int i=0;i<4;i++){
            blankRow = blankIdx/n;
            blankCol = blankIdx - blankRow*n;
            int targetRow = blankRow + dx[i];
            int targetCol = blankCol + dy[i];
            if(targetRow>=0&&targetRow<=n-1&&targetCol>=0&&targetCol<=n-1){
                swappedBlocks = getSwappedBlocks(blankIdx,targetRow*n+targetCol);
                neighbors.push(new Board(swappedBlocks));
            }
        }
        return neighbors;
    }
    private int[] getSwappedBlocks(int i,int j){
        int[] blocks = Arrays.copyOf(blocks1D,blocks1D.length);
        int tmp = blocks[i];
        blocks[i] = blocks[j];
        blocks[j] = tmp;
        return blocks;
    }
    public String toString(){
        StringBuilder board = new StringBuilder();
        board.append(n+"\n");
        for(int i=0;i<blocks1D.length;i++){
            board.append(String.format("%2d ",blocks1D[i]));
            if((i+1)%n == 0) board.append("\n");
        }
        return board.toString();
    }
    public static void main(String[] args){
        In in = new In(args[0]);
        int n = in.readInt();
        int[][] blocks = new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                blocks[i][j] = in.readInt();

        Board initial = new Board(blocks);
        StdOut.println(initial.dimension());
        StdOut.println(initial.toString());
        StdOut.println(initial.hamming());
        StdOut.println(initial.manhattan());
        StdOut.println(initial.twin().toString());
        for(Board nb : initial.neighbors()){
            for(Board subNb : nb.neighbors())
                StdOut.println(subNb.toString());
        }
    }
}

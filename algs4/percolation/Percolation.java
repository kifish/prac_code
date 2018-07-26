
/*
Test 4: Create an n-by-n percolation system; interleave calls to open(),
        percolates(), isOpen(), isFull(), and numberOfOpenSites() until.
        the system percolates. The values of n go up by a factor of sqrt(2).
        The test is passed if n >= 4096 in under 10 seconds.

                        log   union-find     log
         n  seconds   ratio   operations   ratio
     -------------------------------------------
       128     0.16     3.8        86440     1.9
       181     0.63     3.9       170110     2.0
       256     2.50     4.0       337000     2.0
       362    10.06     4.0       689004     2.1
     [ exceeded the time limit of 10.0 seconds ]

==> FAILED
不带路径压缩会比较慢
标准库里UF比WeightedUF快一点,但是在这个评测里UF是禁用的
*/

import edu.princeton.cs.algs4.WeightedQuickUnionUF;


//result : true

public class Percolation{
    private final static int virtualTop = 0;
    private int n;
    private int gridSitesNum;
    private int virtualBottom;
    private int openNum;
    private boolean[] grid;
    private boolean isPercolated;
    private WeightedQuickUnionUF unionInstance;
    private WeightedQuickUnionUF backWash;

    public Percolation(int n){ //create n*n grid, with all sites blocked
        if(n<1){
            throw new IllegalArgumentException("Illegal Argument");
        }
        this.n = n;
        openNum = 0;
        gridSitesNum= n * n + 2; //n*n + virtualTop + virtualBottom
        isPercolated = false;
        virtualBottom = n * n + 1;//0,1,...,n*n+1
        unionInstance = new WeightedQuickUnionUF(gridSitesNum);
        backWash = new WeightedQuickUnionUF(gridSitesNum-1);//no virtualBottom
        grid = new boolean[gridSitesNum];//intially false

    }
    public void open(int row, int col){//open site(row,col),if it is not open already
        isValidArgs(row,col);
        if(isOpen(row,col))
            return;
        int siteId = xyTo1D(row,col);
        grid[siteId] = true;
        openNum++;
        if(1 == row){
            unionInstance.union(virtualTop,siteId);
            backWash.union(virtualTop,siteId);
        }
        if(n == row){
            unionInstance.union(virtualBottom,siteId);
        }
        int[] dx = {-1,0,0,1};
        int[] dy = {0,1,-1,0};
        for(int i=0;i<4;i++){
            int posX = row + dx[i];
            int posY = col + dy[i];
            if(isPosValid(posX,posY) && isOpen(posX,posY)){
                int siteToConnect = xyTo1D(posX,posY);
                unionInstance.union(siteId,siteToConnect);
                backWash.union(siteId,siteToConnect);
            }
        }
    }

    private int xyTo1D(int row, int col){
        int i = (row-1) * n + col;//  WeightedQuickUnionUF的实现中是用到array[0]的
        return i;//本来i应该减1，但因为有virtualTop所以正好不用减
    }
    private boolean isPosValid(int row, int col){
      if(row >= 1&&row <= n &&col>=1 &&col <=n) return true;
      return false;
    }

    private void isValidArgs(int row,int col){
      if(row<1 || row>n)
        throw new IllegalArgumentException("Row index out of bounds");
      if(col<1 || col>n)
        throw new IllegalArgumentException("Col index out of bounds");
    }

    public boolean isOpen(int row,int col){
      isValidArgs(row,col);
      return (grid[xyTo1D(row,col)] == true?true : false);
    }

    public boolean isFull(int row,int col){
      isValidArgs(row,col);
      return backWash.connected(virtualTop,xyTo1D(row,col));//如果该点和虚拟顶点能连通，
    }         //那么说明该点“full”。实际上，如果能与虚拟顶点连通，那么必有一条路径通向虚拟顶点


    public int numberOfOpenSites(){
      return openNum;
    }
    public boolean percolates(){
      if(isPercolated) return true;
      if(unionInstance.connected(virtualTop,virtualBottom)) {
        isPercolated = true;
        return true;
      }
      return false;
    }
    public static void main(String[] args){
      Percolation perc = new Percolation(3);
      perc.open(1,1);
      perc.open(1,2);
      perc.open(2,2);
      perc.open(2,3);
      perc.open(3,1);
      perc.open(3,3);
      System.out.println(perc.percolates());
    }
}


import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
public class PercolationStats{
    private double[] trial;
    private int expTimes;
    public PercolationStats(int n, int trials){//perform trials independent
      if(n<=0 || trials <=0)                              //experiments on an n-by-n grid
        throw new IllegalArgumentException("Illegal Argument");
      trial = new double[trials];
      expTimes = trials;
      for(int i=0;i<trials;i++){
        Percolation perc = new Percolation(n);
        boolean[] LinehasOpenSite = new boolean[n+1];//记录每行是否有一个或以上的open site
        int numOfLine = 0;
        while(true){
          int posX,posY;
          do{
              posX = StdRandom.uniform(n)+1;//[0,N)之间的int数 + 1
              posY = StdRandom.uniform(n)+1;//X:[1,N];Y:[1,N]
              //StdRandom发现posX 是int自动会产生int；如果发现是double自动会产生double
          }while(perc.isOpen(posX,posY));//don't not stop until we find a site which is not open

          perc.open(posX,posY);
          trial[i] += 1;
          if(!LinehasOpenSite[posX]){
            LinehasOpenSite[posX] = true;
            numOfLine++;
          }
          if(n == numOfLine){
            if(perc.percolates()) break;
          }
        }
        trial[i] = trial[i]/(double)(n*n); //the value of p
      }
    }

    public double mean(){
      return StdStats.mean(trial);
    }
    public double stddev(){
      return StdStats.stddev(trial);
    }

    /*
    评测的时候是根据使用StdStats评分的，使用这两个api会得不到分
    public double mean(){ //sample mean of percolation threshold
      double mu = 0;
      for(int i=1;i<=expTimes;i++)
        mu += trial[i];
      return mu/(double)expTimes;
    }

    public double stddev(){ //样本标准差，sample standard deviation of percolation threshold
      if(1 == expTimes) return Double.NaN;
      double sum = 0;
      double mu = mean();
      for(int i = 1;i<=expTimes;i++) sum += (trial[i]-mu)*(trial[i]-mu);
      return Math.sqrt(sum/(double)(expTimes-1));
    }
    */
    public double confidenceLo(){  //low endpoint of 95% confidence interval
      double lo = mean()-1.96*stddev()/Math.sqrt(expTimes);
      return lo;
    }
    public double confidenceHi(){ //high endpoint of 95% confidence interval
      double hi = mean()+1.96*stddev()/Math.sqrt(expTimes);
      return hi;
    }
    public static void main(String[] args){ //test client(described below)
      int n = Integer.parseInt(args[0]);
      int trials = Integer.parseInt(args[1]);
      PercolationStats x = new PercolationStats(n,trials);
      System.out.println("mean                     = "+x.mean());
      System.out.println("stddev                   = "+x.stddev());
      System.out.println("95% confidence interval  = "+"["+x.confidenceLo()+
      ", "+x.confidenceHi()+"]");
    }
}

//javac -Xlint:unchecked Permutation.java
//java Permutation 3 < distinct.txt
import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

public class Permutation{
  public static void main(String[] args){
    RandomizedQueue<String> rq = new RandomizedQueue<String>();
    int k = Integer.parseInt(args[0]);
    int n = 1;
    while(!StdIn.isEmpty() && k>0){
      String item = StdIn.readString();
      if(n <= k)
        rq.enqueue(item);
      else if(StdRandom.uniform(n)<k){
          String useless = rq.dequeue();
          rq.enqueue(item);
          }

      n++;
    }
    for(String s : rq)
      StdOut.println(s);
  }
}
/*
public class Permutation{
  public static void main(String[] args){
    RandomizedQueue<String> rq = new RandomizedQueue<String>();
    int k = Integer.parseInt(args[0]);
    while(!StdIn.isEmpty() && k>0){
      k--;
      rq.enqueue(StdIn.readString());
    }
    while(!StdIn.isEmpty()){
      rq.dequeue();
      rq.enqueue(StdIn.readString());
    }
    //这种实现方法无法实现uniform，因为前面的早出现的item就更可能被dequeue
    for(String s : rq)
      StdOut.println(s);

    /*
    int k = Integer.parseInt(args[0]);
    for(String s : rq){
      if(k<=0) break;
      StdOut.println(s);
      k--;
      //if(k<=0) break; if k=0 ,bug!
    }
    */
/*
  }
}

*/




/*checkstyle 禁止在Permutation.java里面用数组
% custom checkstyle checks for Permutation.java
*-----------------------------------------------------------
[ERROR] Permutation.java:17: Do not declare arrays in this program. [Performance]
[ERROR] Permutation.java:19: Do not declare arrays in this program. [Performance]
Checkstyle ends with 2 errors and 0 warnings.

public class Permutation{
  public static void main(String[] args){
    RandomizedQueue<String> rq = new RandomizedQueue<String>();
    StringBuilder builder = new StringBuilder();
    int cnt = 0;
    while(!StdIn.isEmpty()){
      builder.append(StdIn.readString()).append(' ');
      cnt++;
    }
    if(builder.length()>0) builder.deleteCharAt(builder.length()-1);
    String[] strs = builder.toString().split(" ");
    int k = Integer.parseInt(args[0]);
    int[] idxs =StdRandom.permutation(cnt,k);//int [0,cnt-1];取前k个
    for(int i=0;i<k;i++) rq.enqueue(strs[idxs[i]]);
    for(String s : rq) StdOut.println(s);
  }
}
*/

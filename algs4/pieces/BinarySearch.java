import edu.princeton.cs.algs4.StdIn;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
import java.util.Arrays;

public class BinarySearch{
    public static int rank(int key,int[] a){
        int lo = 0;
        int hi = a.length-1;
        while(lo<=hi){
           int mid = lo + (hi-lo)/2;
           if(key<a[mid]) hi = mid - 1;
           else if (key>a[mid]) lo = mid +1;
           else return mid;
        }
        return -1;
    }


public static void main(String[] args){
    //int[] whitelist = new In(args[0]).readAllInts();
    //如果用上面一行代码，编译不会报错，但是无法pipe，输入重定向
    //下面这一行也无法实现重定向，在Drjava中
    int[] whitelist = In.readInts(args[0]);
    Arrays.sort(whitelist);
    while(!StdIn.isEmpty()){
          int key = StdIn.readInt();
          if(rank(key,whitelist) == -1)
             StdOut.println(key);
    }
}
}
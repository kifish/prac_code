import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.StdOut;
//https://stackoverflow.com/questions/15466105/piping-redirecting-input-from-a-text-file-into-a-java-program-using-drjava
public class readFile { 
  public static void main(String[] args) { 
    //Read file
    In in = new In(args[0]);
    while (!in.isEmpty()) {
      StdOut.println( in.readInt() );
    }
  }
}

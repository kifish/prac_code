import java.util.ArrayList;
import java.util.Arrays;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Insertion;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdDraw;

public class BruteCollinearPoints{
  private ArrayList<LineSegment> lineSgmts;//ArrayList to save line segments
  private Point[] pointSet;

  public BruteCollinearPoints(Point[] points){
    if(points == null) throw new IllegalArgumentException("null point array");
    int len = points.length;
    pointSet = new Point[len];
    for(int i = 0;i<len;i++) {
      if(points[i] == null) throw new IllegalArgumentException("this point is null");
      pointSet[i] = points[i];
    }
    //pointSet = Arrays.copyOf(points,points.length); Is there a point which is null?
    lineSgmts = new ArrayList<LineSegment>();
    for(int i = 0;i<len;i++){
      for(int j = i+1;j<len;j++){
        checkForDuplicates(pointSet[i],pointSet[j]);//avoid duplicate
        for(int k = j+1;k<len;k++){
          //only when the three points are collinear, the fourth point need to be considered
          if(pointSet[i].slopeTo(pointSet[j]) == pointSet[i].slopeTo(pointSet[k])){
            for(int l = k+1;l<len;l++){
              if(pointSet[i].slopeTo(pointSet[k]) == pointSet[i].slopeTo(pointSet[l])){
                Point[] tuple ={pointSet[i],pointSet[j],pointSet[k],pointSet[l]};
                Insertion.sort(tuple);
                lineSgmts.add(new LineSegment(tuple[0],tuple[3]));
              }
            }
          }
        }
      }
    }
  }
  private void checkForDuplicates(Point p,Point q){
    if(p == null || q == null) throw new IllegalArgumentException("Null Point element");
    if(p.compareTo(q)==0) throw new IllegalArgumentException("Duplicate point");
  }

  public int numberOfSegments(){
    return lineSgmts.size();
  }
  public LineSegment[] segments(){
    return lineSgmts.toArray(new LineSegment[numberOfSegments()]);
  }
  public static void main(String[] args){
    In in = new In(args[0]);
    int n = in.readInt();
    Point[] points = new Point[n];
    for(int i = 0;i<n;++i){

      int x = in.readInt();
      int y = in.readInt();
      points[i] = new Point(x,y);
    }
    StdDraw.enableDoubleBuffering();
    StdDraw.setXscale(0,32768);
    StdDraw.setYscale(0,32678);
    for(Point p : points){
      p.draw();
    }
    StdDraw.show();
    BruteCollinearPoints collinear = new BruteCollinearPoints(points);
    for(LineSegment segment : collinear.segments()){
      StdOut.println(segment);
      segment.draw();
    }
    StdDraw.show();
  }
}

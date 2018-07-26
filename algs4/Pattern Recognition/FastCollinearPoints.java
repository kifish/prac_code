import java.util.ArrayList;
import java.util.Arrays;
import edu.princeton.cs.algs4.In;
import edu.princeton.cs.algs4.Merge;
import edu.princeton.cs.algs4.StdDraw;
import edu.princeton.cs.algs4.StdOut;


public class FastCollinearPoints{
  private ArrayList<LineSegment> lineSgmts;
  private Point[] pointSet;
  private ArrayList<Double> sgmtSlopes;
  private ArrayList<Point> lineEndPoints;
  /*
  这个version一开始只用了斜率来判断（如果存在平行线，就出错了），
  slower version也是用斜率判断（但还包括当前遍历的点）

  比较好的实现是，把lineSgmt里改下，把斜率加进去。如果只对线段的一个端点做遍历没法work（
  在一些特殊情况没法判断）

  这份代码暂时还不能跑，有空了再来实现，重写个类似于lineSgmt的私有类即可。
  */

  public FastCollinearPoints(Point[] points){
    if(points == null) throw new IllegalArgumentException("null point array");
    int len = points.length;
    pointSet = new Point[len];
    for(int i = 0;i<len;i++) {
      if(points[i] == null) throw new IllegalArgumentException("this point is null");
      pointSet[i] = points[i];
    }
    //pointSet = Arrays.copyOf(points,points.length); Is there a point which is null?

    lineSgmts = new ArrayList<LineSegment>();
    sgmtSlopes = new ArrayList<Double>();
    lineEndPoints = new ArrayList<Point>();
    Merge.sort(pointSet);
    for(int i= 0;i<len-1;++i){//最后一个点不用遍历,从左下方的点开始遍历
      Point[] pointsAfter = new Point[len-i-1];

      for(int j = 0;j<len-i-1;++j)
        pointsAfter[j] = pointSet[j+i+1];

      double[] slopesBefore = new double[numberOfSlopes()];

      for(int ii=0;ii<slopesBefore.length;ii++){
          slopesBefore[ii] = sgmtSlopes.get(ii);
      }



      Arrays.sort(slopesBefore);
      Arrays.sort(pointsAfter,pointSet[i].slopeOrder());
      addNewSgmts(slopesBefore,pointSet[i],pointsAfter);

    }
  }



  /*slower version
  public FastCollinearPoints(Point[] points){
    if(points == null) throw new IllegalArgumentException("no point array");
    int len = points.length;
    pointSet = Arrays.copyOf(points,len);
    lineSgmts = new ArrayList<LineSegment>();
    Merge.sort(pointSet);
    for(int i= 0;i<len-1;++i){//最后一个点不用遍历,从左下方的点开始遍历
      double[] slopesBefore = new double[i]; //保存存在的每一条线段的斜率
      Point[] pointsAfter = new Point[len-i-1];
      for(int j = 0;j<i;++j)
        slopesBefore[j] = pointSet[i].slopeTo(pointSet[j]);
      for(int j = 0;j<len-i-1;++j)
        pointsAfter[j] = pointSet[j+i+1];
      Arrays.sort(slopesBefore);
      Arrays.sort(pointsAfter,pointSet[i].slopeOrder());
      addNewSgmts(slopesBefore,pointSet[i],pointsAfter);

    }
  }
  */






  private void addNewSgmts(double[] slopesBefore,Point srtPoint,Point[] pointsAfter){
    int cnt = 1;
    int lenOfsub = pointsAfter.length;
    double slope = Double.NEGATIVE_INFINITY;
    double preSlope = Double.NEGATIVE_INFINITY;
    boolean OneLine = false;
    for(int j =0;j<lenOfsub;++j){
      checkForDuplicates(srtPoint,pointsAfter[j]);
      slope = srtPoint.slopeTo(pointsAfter[j]);
      if(preSlope != slope){
        if(cnt >= 3){ //当三点一线的时候,cnt为2,四点即为3

          if(!isSubSgmt(slopesBefore,preSlope)){
            lineSgmts.add(new LineSegment(srtPoint,pointsAfter[j-1]));
            sgmtSlopes.add(preSlope);
            lineEndPoints.add(pointsAfter[j-1]);
          }
          else{
            OneLine = false;
            for(Point curLineSgmt : lineSgmts){
              if(curLineSgmt.p.slopeTo(pointsAfter[j-1]) != slope){   //共线 slope = 0，共点 slope不为0；(4096, 20992) -> (8128, 20992);(4096, 20992) -> (4096, 25088);(5120, 20992) -> (8128, 20992)
                if(curLineSgmt.p.slopeTo(pointsAfter[j-1]) == Double.NEGATIVE_INFINITY){
                  if(curLineSgmt.p.slopeTo(q) == slope){ //.p是private 所以这样不work
                    OneLine = true;
                    break;
                  }
                }
              }

              else{
                if(srtPoint.compareTo(curLineSgmt.p) == 0) continue; //这一行似乎可以去掉
                else if(curLineSgmt.p.compareTo(pointsAfter[j-1]) == 0) OneLine = true;
                //else;
              }
            }
            if(OneLine == false){
              lineSgmts.add(new LineSegment(srtPoint,pointsAfter[j-1]));
              sgmtSlopes.add(preSlope);
              lineEndPoints.add(pointsAfter[j-1]);
            }
          }
        }
        cnt = 1;
      }
      else cnt++;

      preSlope = slope;

      if(j == lenOfsub-1 &&cnt >= 3) {
        if(!isSubSgmt(slopesBefore,preSlope)){
          lineSgmts.add(new LineSegment(srtPoint,pointsAfter[j]));
          sgmtSlopes.add(preSlope);
          lineEndPoints.add(pointsAfter[j]);
        }
        else{
          OneLine = false;
          for(Point curLineSgmt : lineSgmts){
            if(curLineSgmt.p.slopeTo(pointsAfter[j]) != slope){   //共线 slope = 0，共点 slope不为0；(4096, 20992) -> (8128, 20992);(4096, 20992) -> (4096, 25088);(5120, 20992) -> (8128, 20992)
              if(curLineSgmt.p.slopeTo(pointsAfter[j]) == Double.NEGATIVE_INFINITY){
                if(curLineSgmt.p.slopeTo(q) == slope){
                  OneLine = true;
                  break;
                }
              }
            }

            else{
              if(srtPoint.compareTo(curLineSgmt.p) == 0) continue; //这一行似乎可以去掉
              else if(curLineSgmt.p.compareTo(pointsAfter[j]) == 0) OneLine = true;
              //else;
            }
          }

            //(1000, 1000) -> (9000, 9000)
            //(2000, 2000) -> (9000, 9000)
            /*
            point.slopeTo(pointsAfter[j]) == slope
            如果point既是以前的末尾端点，又是现在的起始点，
            那么，导致该合法线段无法被加入
            */

          if(OneLine == false){
            lineSgmts.add(new LineSegment(srtPoint,pointsAfter[j]));
            sgmtSlopes.add(preSlope);
            lineEndPoints.add(pointsAfter[j]);
          }
        }
      }
    }
  }

  private boolean isSubSgmt(double[] slopesBefore,double slope){
    int lo = 0;
    int hi = slopesBefore.length-1;

    while(lo<=hi){
      int mid = lo + (hi-lo)/2;
      if(slope<slopesBefore[mid]) hi = mid -1;
      else if(slope > slopesBefore[mid]) lo = mid +1;
      else return true;
    }
    return false;
  }

  private void checkForDuplicates(Point p,Point q){
    if(p==null || q == null) throw new IllegalArgumentException("point is null");
    if(p.compareTo(q)==0) throw new IllegalArgumentException("duplicate point");
  }
  public int numberOfSegments(){
    return lineSgmts.size();
  }
  //测评不允许有多余的API(public)
  private int numberOfSlopes(){
    return sgmtSlopes.size();
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
    StdDraw.setYscale(0,32768);
    for(Point p : points)
      p.draw();
    StdDraw.show();

    FastCollinearPoints collinear = new FastCollinearPoints(points);
    for(LineSegment segment : collinear.segments()){
      StdOut.println(segment);
      segment.draw();
    }
    StdDraw.show();
  }
}

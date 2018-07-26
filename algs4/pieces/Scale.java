/******************************************************************************
 *  Compilation:  javac Scale.java
 *  Execution:    java Scale filename w h
 *  Dependencies: Picture.java
 *  Data files:   http://introcs.cs.princeton.edu/31datatype/mandrill.jpg
 *
 *  Scales an image to w-by-h and displays both the original
 *  and the scaled version to the screen.
 * 
 *  % java Scale mandrill.jpg 200 300
 *
 *
 ******************************************************************************/
//https://docs.oracle.com/javase/8/javafx/api/javafx/scene/image/Image.html
//import javafx.scene.image.Image;
//要找一下第三方的Picture类
import java.awt.Color;
//import edu.princeton.cs.algs4.Picture;这一行可以

public class Scale {
    public static void main(String[] args) {
        String filename = args[0];
        int w = Integer.parseInt(args[1]);
        int h = Integer.parseInt(args[2]);
        Picture source = new Picture(filename);
        Picture target = new Picture(w, h);
        // StdOut.println("Source image: " + source.width() + "-by-" + source.height());

        for (int ti = 0; ti < w; ti++) {
            for (int tj = 0; tj < h; tj++) {
                int si = ti * source.width()  / w;
                int sj = tj * source.height() / h;
                Color color = source.get(si, sj);
                target.set(ti, tj, color);
            }
        }

        source.show();
        target.show();
    }
}
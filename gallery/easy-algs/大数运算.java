import java.util.Scanner;
import java.math.*;
import java.text.*;
public class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        BigInteger a,b;
        while(cin.hasNext()){
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
            System.out.println(a.add(b));
            System.out.println(a.subtract(b));
            System.out.println(a.multiply(b));
        }
    }
} 

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    private static int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n = cin.nextInt();
        int[] t = new int[1000];
        for (int i = 0; i < n; ++i) {
            t[i] = cin.nextInt();
        }
        BigInteger a = BigInteger.ZERO;
        BigInteger b = BigInteger.ZERO;
        boolean first = true;
        for (int i = 1; i < n; ++i) {
            if (t[i] != t[0]) {
                int x = t[0] * t[i];
                int y = Math.abs(t[0] - t[i]);
                int g = gcd(x, y);
                BigInteger xx = BigInteger.valueOf(x / g);
                BigInteger yy = BigInteger.valueOf(y / g);
                if (first) {
                    first = false;
                    a = xx;
                    b = yy;
                } else {
                    a = a.divide(a.gcd(xx)).multiply(xx);
                    b = b.gcd(yy);
                }
            }
        }
        if (a.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
            System.out.print(a.divide(BigInteger.valueOf(2)).toString());
            System.out.print(" ");
            System.out.println(b.toString());
        } else {
            System.out.print(a.toString());
            System.out.print(" ");
            System.out.println(b.multiply(BigInteger.valueOf(2)).toString());
        }
    }
}

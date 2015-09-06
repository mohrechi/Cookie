import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

    private static final int MAXN = 100 + 5;
    private static BigInteger[] a = new BigInteger[MAXN];

    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int T = cin.nextInt();
        for (int i = 0; i < MAXN; ++i) {
            a[i] = BigInteger.ZERO;
        }
        while (T-- > 0) {
            int n = cin.nextInt();
            cin.nextLine();
            String[] nums = cin.nextLine().split(" ");
            int zeroNum = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = new BigInteger(nums[i]);
                if (a[i].compareTo(BigInteger.ZERO) == 0) {
                    ++zeroNum;
                }
            }
            boolean same = true;
            boolean valid = true;
            for (int i = 1; i < n && valid; ++i) {
                if (a[i].compareTo(a[0]) != 0) {
                    same = false;
                    if (i > 1) {
                        valid = false;
                    }
                    break;
                }
            }
            if (!same && zeroNum > 0) {
                valid = false;
            }
            if (!same && valid) {
                for (int i = 2; i < n; ++i) {
                    if (a[1].multiply(a[i - 1]).compareTo(a[0].multiply(a[i])) != 0) {
                        valid = false;
                        break;
                    }
                }
            }
            System.out.println(valid ? "Yes" : "No");
        }
        cin.close();
    }

}

import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main {
    private static final int MAXN = 100 + 5;
    private static final int MAXM = 1000;
    private static int d, n;
    private static int[] a = new int[MAXN];
    private static int[] b = new int[MAXN];
    private static int lenM, lenK;
    private static int[] divM = new int[MAXM];
    private static int[] divK = new int[MAXM];
    private static BigInteger m, k;
    private static BigInteger[] modulo = new BigInteger[MAXM];
    private static BigInteger[] remainder = new BigInteger[MAXM];
    private static BigInteger x, y;
    private static BigInteger mm, aa;

    private static BigInteger exgcd(BigInteger a, BigInteger b) {
        if (b.compareTo(BigInteger.ZERO) == 0) {
            x = BigInteger.ONE;
            y = BigInteger.ZERO;
            return a;
        }
        BigInteger g = exgcd(b, a.mod(b));
        BigInteger t = y;
        y = x.subtract(a.divide(b).multiply(y));
        x = t;
        return g;
    }

    private static boolean reduce(BigInteger m1, BigInteger a1, BigInteger m2, BigInteger a2) {
        BigInteger c = a2.subtract(a1);
        BigInteger g = exgcd(m1, m2);
        if (c.mod(g).compareTo(BigInteger.ZERO) != 0) {
            return false;
        }
        BigInteger x0 = x.multiply(c.divide(g));
        m2 = m2.divide(g);
        x0 = x0.mod(m2).add(m2).mod(m2);
        aa = a1.add(x0.multiply(m1));
        mm = m1.multiply(m2);
        return true;
    }

    private static BigInteger solve() {
        BigInteger m1, a1, m2, a2;
        m1 = modulo[0];
        a1 = remainder[0];
        for (int i = 1; i < n; ++i) {
            m2 = modulo[i];
            a2 = remainder[i];
            if (!reduce(m1, a1, m2, a2)) {
                return BigInteger.valueOf(-1);
            }
            m1 = mm;
            a1 = aa;
        }
        return a1;
    }

    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        while (true) {
            d = cin.nextInt();
            if (d == -1) {
                break;
            }
            for (int i = 1; i < d; ++i) {
                a[i] = cin.nextInt();
            }
            for (int i = 0; i < d; ++i) {
                b[i] = cin.nextInt();
            }
            m = new BigInteger(cin.next());
            k = new BigInteger(cin.next());
            lenM = 0;
            while (!m.equals(BigInteger.ZERO)) {
                divM[lenM++] = m.mod(BigInteger.valueOf(d)).intValue();
                m = m.divide(BigInteger.valueOf(d));
            }
            lenK = 0;
            while (!k.equals(BigInteger.ZERO)) {
                divK[lenK++] = k.mod(BigInteger.valueOf(d)).intValue();
                k = k.divide(BigInteger.valueOf(d));
            }
            if (lenM == 0 && lenK == 0) {
                System.out.println(0);
            } else if (lenM != lenK) {
                System.out.println("NO");
            } else {
                n = lenM;
                boolean flag = true;
                for (int i = 0; i < n - 1; ++i) {
                    int start = b[divM[i]];
                    int pos = start;
                    int loop = 0;
                    int step = -1;
                    while (true) {
                        ++loop;
                        pos = b[pos];
                        if (pos == b[divK[i]]) {
                            step = loop;
                        }
                        if (pos == start) {
                            break;
                        }
                    }
                    if (step == -1) {
                        flag = false;
                        break;
                    }
                    modulo[i] = BigInteger.valueOf(loop);
                    remainder[i] = BigInteger.valueOf(step % loop);
                }
                int start = a[divM[n - 1]];
                int pos = start;
                int loop = 0;
                int step = -1;
                while (true) {
                    ++loop;
                    pos = a[pos];
                    if (pos == a[divK[n - 1]]) {
                        step = loop;
                    }
                    if (pos == start) {
                        break;
                    }
                }
                if (step == -1) {
                    flag = false;
                } else {
                    modulo[n - 1] = BigInteger.valueOf(loop);
                    remainder[n - 1] = BigInteger.valueOf(step % loop);
                }
                if (flag) {
                    BigInteger ans = solve();
                    if (ans.compareTo(BigInteger.valueOf(-1)) != 0) {
                        System.out.println(ans.toString());
                    } else {
                        System.out.println("NO");
                    }
                } else {
                    System.out.println("NO");
                }
            }
        }
    }
}

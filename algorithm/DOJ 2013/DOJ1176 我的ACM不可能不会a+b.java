import java.util.Scanner;
import java.math.BigInteger;

public class Main
{
    public static void main(String[] args)
    {
        int T;
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        for (int t = 0; t < T; ++t)
        {
            String s1 = cin.next();
            String s2 = cin.next();
            BigInteger a = new BigInteger(s1);
            BigInteger b = new BigInteger(s2);
            System.out.println(a.multiply(b));
        }
    }
}

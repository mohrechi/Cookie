import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int n;
        BigInteger a;
        for(;;)
        {
            n=cin.nextInt();
            if(n==-1) break;
            a=BigInteger.valueOf(1);
            for(int i=2;i<=n;i++)
            {
                a=a.multiply(BigInteger.valueOf(4*i-2));
                a=a.divide(BigInteger.valueOf(i+1));
            }
            System.out.println(a);
        }
    }
}

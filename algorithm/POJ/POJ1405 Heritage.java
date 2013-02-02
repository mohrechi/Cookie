import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int n;
        BigInteger a[]=new BigInteger[19];
        BigInteger t=BigInteger.valueOf(2);
        n=cin.nextInt();
        a[0]=BigInteger.valueOf(1);
        a[1]=BigInteger.valueOf(2);
        System.out.println(2);
        for(int i=2;i<=n;i++)
        {
        	a[i]=t.add(a[0]);
            t=t.multiply(a[i]);
            System.out.println(a[i]);
        }
    }
}

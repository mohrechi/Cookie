import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        BigInteger a[]=new BigInteger[101];
        a[1]=BigInteger.valueOf(1);
        for(int i=2;i<=100;i++)
        {
        	a[i]=BigInteger.valueOf(1);
        	for(int j=1;j<i-1;j++)
        	{
        		a[i]=a[i].add(a[j]);
        	}
        	a[i]=a[i].add(a[i-1]);
        	a[i]=a[i].add(a[i-1]);
        }
        while(cin.hasNext())
        {
        	int b;
        	b=cin.nextInt();
            System.out.println(a[b].toString());
        }
    }
}

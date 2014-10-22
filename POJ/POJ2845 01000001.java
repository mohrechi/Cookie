import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        int n,i=1;
        String s;
        BigInteger x,y,a;
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        n=cin.nextInt();
        for(i=1;i<=n;i++)
        {
        	s=cin.next();
        	x=new BigInteger(s,2);
        	s=cin.next();
        	y=new BigInteger(s,2);
        	a=x.add(y);
        	System.out.printf("%d ",i);
        	System.out.println(a.toString(2));
        }
    }
}

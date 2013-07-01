import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int n,i;
        n=cin.nextInt();
        String s;
        BigInteger x,y,a;
        for(i=1;i<=n;i++)
        {
        	s=cin.next();
        	x=new BigInteger(s,10);
        	s=cin.next();
        	y=new BigInteger(s,10);
        	a=x.add(y);
        	System.out.println("Case "+i+":");
        	System.out.println(x.toString()+" + "+y.toString()+" = "+a.toString());
        	if(i<n)System.out.println();
        }
    }
}

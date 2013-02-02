import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int n;
        BigInteger a,b;
        for(;;)
        {
        	n=cin.nextInt();
        	if(n==0) break;
        	a=new BigInteger(cin.next(),n);
        	b=new BigInteger(cin.next(),n);
        	a=a.mod(b);
        	System.out.println(a.toString(n));
        }
    }
}

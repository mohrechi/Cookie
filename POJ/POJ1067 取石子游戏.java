import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        long a,b,t;
    	double x;
    	x=(1+Math.sqrt(5))/2;
    	while(cin.hasNext())
    	{
    		a=cin.nextLong();
    		b=cin.nextLong();
    		if(a>b)
    		{
    			t=a;a=b;b=t;
    		}
    		if(Math.floor(x*(b-a))==a) System.out.printf("0\n");
    		else System.out.printf("1\n");
    	}

    }
}

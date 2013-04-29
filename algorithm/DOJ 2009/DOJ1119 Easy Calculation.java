import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args)
    {
        String s;
        BigInteger a = new BigInteger("0");
        BigInteger b = new BigInteger("0");
        boolean add = false;
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        while(cin.hasNext())
        {
        	s = cin.nextLine();
        	for(int i=0;i<s.length();++i)
        	{
        		if(s.charAt(i) == '+' || s.charAt(i) == '*')
        		{
        			a = new BigInteger(s.substring(0, i));
        			b = new BigInteger(s.substring(i+1, s.length()));
        			add = (s.charAt(i) == '+');
        		}
        	}
        	if(add)
        	{
        		a = a.add(b);
        	}
        	else
        	{
        		a = a.multiply(b);
        	}
    		System.out.println(a.toString());
        }
    }
}

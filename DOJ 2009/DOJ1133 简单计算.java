import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        while(cin.hasNext())
        {
            BigInteger in = new BigInteger(cin.next());
            BigInteger left = BigInteger.ONE;
            BigInteger right = new BigInteger(in.toString());
            BigInteger ans = BigInteger.ONE;
            while(left.compareTo(right) <= 0)
            {
            	BigInteger mid = left.add(right).divide(BigInteger.valueOf(2));
            	int s = mid.multiply(mid).multiply(mid).compareTo(in);
            	if(s == 0)
            	{
            		ans = mid;
            		break;
            	}
            	else if(s == 1)
            	{
            		right = mid.subtract(BigInteger.ONE);
            	}
            	else
            	{
            		ans = mid;
            		left = mid.add(BigInteger.ONE);
            	}
            }
            System.out.println(ans.toString());
        }
    }
}

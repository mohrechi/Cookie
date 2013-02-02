import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Main
{

    public static void main(String args[])
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        while(true)
        {
        	BigInteger a = new BigInteger(cin.nextLine());
        	if(a.compareTo(BigInteger.ZERO) == 0)
        	{
        		break;
        	}
        	if(a.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO) == 0)
        	{
        		System.out.println(1);
        	}
        	else
        	{
        		System.out.println(0);
        	}
        }
    }
}

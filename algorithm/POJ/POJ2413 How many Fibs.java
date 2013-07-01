import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigInteger fib[] = new BigInteger[500];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        for(int i=2;i<500;++i)
        {
            fib[i] = fib[i-1].add(fib[i-2]);
        }
        while(cin.hasNext())
        {
            BigInteger start = new BigInteger(cin.next());
            BigInteger end   = new BigInteger(cin.next());
            if(start.compareTo(BigInteger.ZERO) == 0 &&
                end.compareTo(BigInteger.ZERO) == 0)
            {
                break;
            }
            int result = 0;
            for(int i=2;i<500;++i)
            {
                if(fib[i].compareTo(start) >= 0 && fib[i].compareTo(end) <= 0)
                {
                    ++ result;
                }
            }
            System.out.println(result);
        }
    }
}

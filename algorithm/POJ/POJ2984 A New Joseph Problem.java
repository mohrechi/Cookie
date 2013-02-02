import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args)
    {
        int i,count;
        BigInteger n,ans;
        String s;
        Scanner cin = new Scanner (System.in);
        while(cin.hasNext())
        {
            n = cin.nextBigInteger();
            s = n.toString(2);
            count = 0;
            for(i=0;i<s.length();i++)
                if(s.charAt(i)=='1')
                    count++;
            ans=BigInteger.valueOf(2);
            ans = ans.pow(count);
            ans = ans.subtract(BigInteger.ONE);
            System.out.println(ans);
        }
    }
}

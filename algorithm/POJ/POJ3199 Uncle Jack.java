import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        int b;
        BigInteger a,c;
        c=BigInteger.valueOf(0);
        for(;;)
        {
            a=new BigInteger(cin.next(),10);
            b=cin.nextInt();
            if(a.compareTo(c)==0&b==0) break;
            a=a.pow(b);
            System.out.println(a);
        }
    }
}

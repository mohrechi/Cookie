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
        a=new BigInteger(cin.next(),10);
        b=new BigInteger(cin.next(),10);
        a=a.multiply(b);
        System.out.println(a);
    }
}

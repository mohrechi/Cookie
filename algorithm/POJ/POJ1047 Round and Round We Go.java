import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        String input;
        BigInteger a,b;
        while(cin.hasNext())
        {
            input = cin.nextLine();
            a = new BigInteger(input);
            b = BigInteger.valueOf(input.length()+1);
            a = a.multiply(b);
            System.out.print(input);
            input = a.toString();
            boolean flag = true;
            for(int i=0;i<input.length();i++)
            {
                if(input.charAt(i)!='9')
                {
                    flag=false;
                    break;
                }
            }
            if(flag) System.out.println(" is cyclic");
            else System.out.println(" is not cyclic");
        }
    }
}

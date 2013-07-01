import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner (new BufferedInputStream(System.in));
        String s;
        for(;;)
        {
        	s=cin.next();
        	if (s==null)return;
        	BigDecimal a=new BigDecimal(0);
        	BigDecimal b=new BigDecimal(0.125);
        	BigDecimal c=new BigDecimal(8);
        	for(int i=2;i<s.length();i++)
            {
                a=a.add(b.multiply(new BigDecimal(s.charAt(i)-48)));
                b=b.divide(c);
            }
            System.out.println(s+" [8] = "+a.toString()+" [10]");
        }
    }
}

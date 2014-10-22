import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class Main
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        BigDecimal a;
        int n;
        while(cin.hasNext())
        {
            a = cin.nextBigDecimal();
            n = cin.nextInt();
            a = a.pow(n).stripTrailingZeros();
            String output = a.toPlainString();
            if(output.charAt(0)=='0')
            {
                output = output.substring(1);
            }
            System.out.println(output);
        }
    }
}

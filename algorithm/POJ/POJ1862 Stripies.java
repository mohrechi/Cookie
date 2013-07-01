import java.io.*;
import java.math.*;
import java.text.DecimalFormat;
import java.util.*;

public class Main
{
    public static void sort(double w[], int n)
    {
        double temp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(w[i]>w[j])
                {
                    temp = w[i];
                    w[i] = w[j];
                    w[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n;
        double w[] = new double[100];
        n=cin.nextInt();
        for(int i=0;i<n;i++)
        {
            w[i] = cin.nextDouble();
        }
        for(int i=0;i<n-1;i++)
        {
            sort(w, n-i);
            w[n-i-2]=2.0*Math.sqrt(w[n-i-1]*w[n-i-2]);
        }
        DecimalFormat f = new DecimalFormat("#0.000");
        System.out.println(f.format(w[0]));
    }
}

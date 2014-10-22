import java.io.*;
import java.util.*;

public class Main 
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n, max, a[], min[];
        a = new int[1005];
        min = new int[1005];
        n = cin.nextInt();
        for(int i = 0; i < n; i++)
        {
            a[i] = cin.nextInt();
            min[i] = 1;
        }
        max = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(a[i] > a[j] && min[j] + 1 > min[i])
                {
                    min[i] = min[j] + 1;
                    if(min[i] > max)
                    {
                        max = min[i];
                    }
                }
            }
        }
        System.out.println(max);
    }
}

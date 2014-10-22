import java.io.*;
import java.util.*;

public class Main
{
    public static class Int
    {
        int num;
        public Int(int x)
        {
            num = x;
        }
    }
    public static class Compare implements Comparator
    {
        public int compare(Object o1, Object o2)
        {
            Int x = (Int) o1;
            Int y = (Int) o2;
            return x.num-y.num;
        }
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int n,k,t;
        List number = new ArrayList();
        n=cin.nextInt();
        for(int i=0;i<n;i++)
        {
            t=cin.nextInt();
            number.add(new Int(t));
        }
        Compare comparator = new Compare();
        Collections.sort(number, comparator);
        cin.next();
        k=cin.nextInt();
        for(int i=0;i<k;i++)
        {
            t=cin.nextInt();
            System.out.println(((Int)number.get(t-1)).num);
        }
    }
}

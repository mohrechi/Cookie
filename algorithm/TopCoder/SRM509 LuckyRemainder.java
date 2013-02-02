package SRM509;

public class LuckyRemainder 
{
    public int getLuckyRemainder(String X)
    {
        long mul = (long) Math.pow((double)2, (double)(X.length() - 1));
        long sum = 0;
        for(int i=0;i<X.length();i++)
        {
            sum += mul * (X.charAt(i) - '0');
        }
        return (int) (sum % 9);
    }
}
//410.82/500
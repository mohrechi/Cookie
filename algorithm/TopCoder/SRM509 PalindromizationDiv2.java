package SRM509;

public class PalindromizationDiv2 
{
    public int getMinimumCost(int X)
    {
        int min = 0;
        while(true)
        {
            if(isPalindrom(X+min) || isPalindrom(X-min))
            {
                break;
            }
            min ++;
        }
        return min;
    }
    
    private boolean isPalindrom(int x)
    {
        if(x<0) return false;
        String deal = "" + x;
        for(int i=0;i<deal.length()/2;++i)
        {
            if(deal.charAt(deal.length() - i - 1) !=  deal.charAt(i))
            {
                return false;
            }
        }
        return true;
    }
}
//195.45/250
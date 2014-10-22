package SRM513;

public class YetAnotherIncredibleMachine 
{
    public int countWays(int[] platformMount, int[] platformLength, int[] balls)
    {
        long result = 0;
        int way[] = new int[platformMount.length];
        for(int i=0;i<platformMount.length;i++)
        {
            way[i] = 0;
            int start = platformMount[i] - platformLength[i];
            int end = platformMount[i];
            for(int j=0;j<=platformLength[i];j++)
            {
                int k;
                for(k=0;k<balls.length;k++)
                {
                    if(balls[k] >= start && balls[k] <= end)
                    {
                        break;
                    }
                }
                if(k == balls.length)
                {
                    way[i] ++;
                    result = 1;
                }
                start ++;
                end ++;
            }
        }
        for(int i=0;i<platformMount.length;i++)
        {
            if(way[i] > 0)
            {
                result = (result * way[i]) % 1000000009;
            }
        }
        return (int)result;
    }
}

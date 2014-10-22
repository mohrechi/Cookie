package TCHSSRM1;

public class SpeedRadar 
{
    public double averageSpeed(int minLimit, int maxLimit, int[] readings)
    {
        int sum = 0, num = 0;
        for(int i=0;i<readings.length;i++)
        {
            if(readings[i]>=minLimit && readings[i]<=maxLimit)
            {
                sum+=readings[i];
                num++;
            }
        }
        if((readings.length-num)*10 > readings.length)
        {
            return 0.0;
        }
        return (double)sum/num;
    }
}

package SRM504_5;

public class TheJackpotDivTwo 
{
    public int[] find(int[] money, int jackpot)
    {
        if(money.length==1)
        {
            money[0] += jackpot;
            return money;
        }
        for(int i=0;i<money.length;++i)
        {
            for(int j=i+1;j<money.length;++j)
            {
                if(money[i]>money[j])
                {
                    money[i]^=money[j];
                    money[j]^=money[i];
                    money[i]^=money[j];
                }
            }
        }
        while(jackpot>0)
        {
            int min = money[1]-money[0]+1;
            if(jackpot>=min)
            {
                money[0] += min;
                jackpot -= min;
                int i = 0;
                while(i<money.length-1 && money[i]>money[i+1])
                {
                    money[i]^=money[i+1];
                    money[i+1]^=money[i];
                    money[i]^=money[i+1];
                    i ++;
                }
            }
            else
            {
                money[0] += jackpot;
                jackpot = 0;
            }
        }
        return money;
    }
}

package SRM506;

public class SlimeXSlimesCity 
{
    public int merge(int[] population)
    {
        int ansNum = 0;
        int temp[] = new int[population.length];
        long popNum;
        for(int k=0;k<population.length;k++)
        {
            popNum = population[k];
            for(int i=0;i<population.length;i++)
            {
                if(i==k) temp[i] = 2000000000;
                else temp[i] = population[i];
            }
            for(int i=0;i<temp.length;i++)
            {
                for(int j=i+1;j<temp.length;j++)
                {
                    if(temp[i]>temp[j])
                    {
                        temp[i]^=temp[j];
                        temp[j]^=temp[i];
                        temp[i]^=temp[j];
                    }
                }
            }
            int i;
            for(i=0;i<temp.length-1;i++)
            {
                if(popNum>=temp[i])
                {
                    popNum+=temp[i];
                }
                else
                {
                    break;
                }
            }
            if(i==temp.length-1)
            {
                ansNum++;
            }
        }
        return ansNum;
    }
}

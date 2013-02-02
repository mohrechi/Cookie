package SRM506;

public class SlimeXSlimeRancher2 
{
    public int train(int[] attributes)
    {
        int max = 0;
        for(int i=0;i<attributes.length;++i)
        {
            if(attributes[i]>max)
            {
                max = attributes[i];
            }
        }
        int ans=0;
        for(int i=0;i<attributes.length;++i)
        {
            ans += max-attributes[i];
        }
        return ans;
    }
}

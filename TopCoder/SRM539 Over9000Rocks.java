package SRM539;

public class Over9000Rocks {
	public int countPossibilities(int[] lowerBound, int[] upperBound){
		int choose = 1 << lowerBound.length;
		int low[] = new int[choose];
		int up[] = new int[choose];
		for(int i=1;i<choose;++i)
		{
			low[i] = up[i] = 0;
			for(int j=0;j<lowerBound.length;++j)
			{
				if((i&(1<<j))>0)
				{
					low[i] += lowerBound[j];
					up[i] += upperBound[j];
				}
			}
		}
		for(int i=1;i<choose;++i)
		{
			for(int j=i+1;j<choose;++j)
			{
				if(low[i] > low[j])
				{
					int temp;
					temp = low[i];
					low[i] = low[j];
					low[j] = temp;
					temp = up[i];
					up[i] = up[j];
					up[j] = temp;
				}
			}
		}
		int ret = 0;
		int left = low[1];
		int right = up[1];
		for(int i=2;i<choose;++i)
		{
			if(low[i] > right)
			{
				if(right > 9000)
				{
					ret += right - (left>9000?left:9001) + 1;
				}
				left = low[i];
				right = up[i];
			}
			else
			{
				if(up[i] > right)
				{
					right = up[i];
				}
			}
		}
		if(right > 9000)
		{
			ret += right - (left>9000?left:9001) + 1;
		}
		return ret;
	}
}//168.32/250

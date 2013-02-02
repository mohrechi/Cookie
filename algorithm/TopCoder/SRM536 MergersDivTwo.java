package SRM536;

public class MergersDivTwo 
{
	double ans;
	int min, length;
	
	void search(int[] revenues, int position, double value)
	{
		if(position == length)
		{
			if(value > ans)
			{
				ans = value;
			}
			return;
		}
		if(position == 0)
		{
			for(int i = min;i<=length - position;++i)
			{
				double temp = value;
				for(int j=0;j<i;++j)
				{
					temp += revenues[position + j];
				}
				temp /= i;
				search(revenues, position + i, temp);
			}
		}
		else
		{
			if(position + min - 1 > length)
			{
				return;
			}
			for(int i = min - 1;i<=length - position - 1;++i)
			{
				double temp = value;
				for(int j=0;j<i;++j)
				{
					temp += revenues[position + j];
				}
				temp /= (i+1);
				search(revenues, position + i, temp);
			}
		}
	}
	
	public double findMaximum(int[] revenues, int k)
	{
		min = k;
		length = revenues.length;
		int temp;
		for(int i=0;i<revenues.length;++i)
		{
			for(int j=i+1;j<revenues.length;++j)
			{
				if(revenues[i] > revenues[j])
				{
					temp = revenues[i];
					revenues[i] = revenues[j];
					revenues[j] = temp;
				}
			}
		}
		ans = - 100000.0;
		search(revenues, 0, 0.0);
		return ans;
	}
}

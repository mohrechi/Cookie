package SRM536;

public class BinaryPolynomialDivTwo 
{
	public int countRoots(int[] a)
	{
		int ans = 0;
		if(a[0] == 0)
		{
			++ ans;
		}
		int sum = 0;
		for(int i=0;i<a.length;++i)
		{
			sum += a[i];
		}
		if(sum % 2 == 0)
		{
			++ ans;
		}
		return ans;
	}
}

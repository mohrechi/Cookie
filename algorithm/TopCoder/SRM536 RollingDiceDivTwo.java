package SRM536;

public class RollingDiceDivTwo 
{
	public int minimumFaces(String[] rolls)
	{
		int temp;
		int roll[][] = new int [rolls.length][rolls[0].length()];
		for(int i=0;i<rolls.length;++i)
		{
			for(int j=0;j<rolls[i].length();++j)
			{
				roll[i][j] = rolls[i].charAt(j) - '0';
			}
			for(int j=0;j<roll[i].length;++j)
			{
				for(int k=j+1;k<roll[i].length;++k)
				{
					if(roll[i][j] > roll[i][k])
					{
						temp = roll[i][j];
						roll[i][j] = roll[i][k];
						roll[i][k] = temp;
					}
				}
			}
		}
		int sum = 0;
		for(int i=0;i<roll[0].length;++i)
		{
			for(int j=1;j<roll.length;++j)
			{
				if(roll[j][i] > roll[0][i])
				{
					roll[0][i] = roll[j][i];
				}
			}
			sum += roll[0][i];
		}
		return sum;
	}
}

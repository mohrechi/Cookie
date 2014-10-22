package SRM521;

public class MissingParentheses 
{
    public int count;
    public String s;
    public int dp[][];
    public int prev[][];
    
    private void counter(int i, int j)
    {
        if(i>j)
        {
            return;
        }
        if(i==j)
        {
            count += 2;
        }
        else if(prev[i][j] == -1)
        {
            count +=2;
            counter(i+1, j-1);
        }
        else
        {
            counter(i, prev[i][j]);
            counter(prev[i][j]+1, j);
        }
    }
    
    public int countCorrections(String par)
    {
        this.count = 0;
        this.s = par;
        this.dp = new int[200][200];
        this.prev = new int[200][200];
        for(int i=0;i<s.length();++i)
        {
            dp[i][i] = 1;
        }
        for(int st=1;st<s.length();++st)
        {
            for(int i=0;i+st<s.length();++i)
            {
                int j = i + st;
                dp[i][j] = 10000000;
                if(s.charAt(i) == '(' && s.charAt(j) == ')')
                {
                    if(dp[i][j]>dp[i+1][j-1])
                    {
                        dp[i][j] = dp[i+1][j-1];
                        prev[i][j] = -1;
                    }
                }
                for(int k=i;k<j;++k)
                {
                    if(dp[i][j] > dp[i][k] + dp[k+1][j])
	            {
	                dp[i][j] = dp[i][k] + dp[k+1][j];
	                prev[i][j] = k;
	            }
                }
            }
        }
        counter(0, s.length() - 1);
        return count - s.length();
    }
}
//178.64/250
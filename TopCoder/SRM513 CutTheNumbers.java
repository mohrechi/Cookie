package SRM513;

public class CutTheNumbers 
{
    public int maxSum;
    public boolean visit[][];
    
    public void dfs(String[] board, int sum)
    {
        if(sum > maxSum)
        {
            maxSum = sum;
        }
        for(int i=0;i<visit.length;i++)
        {
            for(int j=0;j<visit[0].length;j++)
            {
                if(!visit[i][j])
                {
                    for(int x = 1;x<=visit.length-i;x++)
                    {
                        boolean flag = true;
                        for(int y=0;y<x;y++)
                        {
                            if(visit[i+y][j])
                            {
                                flag = false;
                            }
                        }
                        if(flag)
                        {
                             int count = 0;
                            for(int y=0;y<x;y++)
                            {
                                visit[i+y][j] = true;
                                count = count * 10 + board[i+y].charAt(j) - '0';
                            }
                            dfs(board, sum + count);
                            for(int y=0;y<x;y++)
                            {
                                visit[i+y][j] = false;
                            }
                        }
                    }
                    for(int x = 1;x<=visit[0].length - j;x++)
                    {
                        boolean flag = true;
                        for(int y=0;y<x;y++)
                        {
                            if(visit[i][j+y])
                            {
                                flag = false;
                            }
                        }
                        if(flag)
                        {
                            int count = 0;
                            for(int y=0;y<x;y++)
                            {
                                visit[i][j+y] = true;
                                count = count * 10 + board[i].charAt(j+y) - '0';
                            }
                            dfs(board, sum + count);
                            for(int y=0;y<x;y++)
                            {
                                visit[i][j+y] = false;
                            }
                        }
                    }
                    return;
                }
            }
        }
    }
    
    public int maximumSum(String[] board)
    {
        maxSum = 0;
        visit = new boolean[board.length][board[0].length()];
        for(int i=0;i<visit.length;i++)
        {
            for(int j=0;j<visit[0].length;j++)
            {
                visit[i][j] = false;
            }
        }
        dfs(board, 0);
        return maxSum;
    }
}
//628.88/1000
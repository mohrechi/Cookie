#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,m,seat[20][20],rseat[20],sit[20][5000];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            rseat[i]=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&seat[i][j]);
                rseat[i]+=((!seat[i][j])<<j);
            }
        }
        int mbit=1<<m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mbit;j++)
            {
                sit[i][j]=0;
                if(!(j&rseat[i]) && !(j&(j<<1)))
                {
                    if(i)
                    {
                        for(int k=0;k<mbit;k++)
                        {
                            if(sit[i-1][k] && !(j&k))
                            {
                                sit[i][j]+=sit[i-1][k];
                                while(sit[i][j]>100000000)
                                {
                                    sit[i][j]-=100000000;
                                }
                            }
                        }
                    }
                    else
                    {
                        sit[i][j]=1;
                    }
                }
            }
        }
        int answer=0;
        for(int i=0;i<mbit;i++)
        {
            answer+=sit[n-1][i];
        }
        printf("%d\n",answer%100000000);
    }
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

int fact3[11], bad[10][150];
int stateA[10], stateB[10];
int m,n,dp[2][59049];

inline int Max(int a, int b)
{
    return a>b?a:b;
}

void initFact3()
{
    fact3[0]=1;
    for(int i=1;i<11;i++)
    {
        fact3[i]=fact3[i-1]*3;
    }
}

int makeState(int state[10])
{
    int temp=0;
    for(int i=0;i<m;i++)
    {
        temp+=state[i]*fact3[i];
    }
    return temp;
}

void getState(int hash, int state[10])
{
    for(int i=0;i<m;i++)
    {
        state[i]=hash%3;
        hash/=3;
    }
}

void initial()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++)
    {
        stateA[i]=bad[i][0]+1;
    }
    dp[0][makeState(stateA)]=0;
}

void dfs(int x, int y, int count)
{
    if(x>=m)
    {
        dp[y&1][makeState(stateB)]=Max(dp[y&1][makeState(stateB)],count);
        return;
    }
    if(x<m-2 && stateB[x]==0 && stateB[x+1]==0 && stateB[x+2]==0)
    {
        stateB[x]=stateB[x+1]=stateB[x+2]=2;
        dfs(x+3,y,count+1);
        stateB[x]=stateB[x+1]=stateB[x+2]=0;
    }
    if(x<m-1 && stateA[x]==0 && stateA[x+1]==0 && stateB[x]==0 && stateB[x+1]==0 )
    {
        stateB[x]=stateB[x+1]=2;
        dfs(x+2,y,count+1);
        stateB[x]=stateB[x+1]=0;
    }
    dfs(x+1,y,count);
}

int main()
{
    int d,k,x,y;
    initFact3();
    cin>>d;
    while(d--)
    {
        cin>>n>>m>>k;
        memset(bad,0,sizeof(bad));
        while(k--)
        {
            cin>>x>>y;
            bad[y-1][x-1]=1;
        }
        initial();
        for(int i=1;i<n;i++)
        {
            memset(dp[i&1],-1,sizeof(dp[i&1]));
            for(int j=0;j<fact3[m];j++)
            {
                if(dp[(i-1)&1][j]!=-1)
                {
                    getState(j,stateA);
                    for(int k=0;k<m;k++)
                    {
                        if(bad[k][i])
                        {
                            stateB[k]=2;
                        }
                        else
                        {
                            if(stateA[k]==2)
                            {
                                stateB[k]=1;
                            }
                            else
                            {
                                stateB[k]=0;
                            }
                        }
                    }
                    dfs(0,i,dp[(i-1)&1][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<fact3[m];i++)
        {
            ans=Max(ans,Max(dp[0][i],dp[1][i]));
        }
        cout<<ans<<endl;
    }
}

#include<iostream>
using namespace std;
int n,graph[205][205];

int maxflow()
{
    int sum(0);
    for(;;)
    {
        int min(2100000000),queue[2][205],qf=2,qr=1, visited[205];
        queue[0][1]=1, queue[1][1]=0;
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
        }
        for(;qr<qf;)
        {
            int i;
            for(i=2;i<=n;i++)
            {
                if(not visited[i] and graph[queue[0][qr]][i]>0)
                {
                    queue[0][qf]=i, queue[1][qf++]=qr, visited[i]=1;
                    if(i==n) break;
                }
            }
            qr++;
            if(i==n) break;
        }
        if(queue[0][--qf]!=n) return sum;
        for(int t(qf);t>1;)
        {
            if(graph[queue[0][queue[1][t]]][queue[0][t]]<min and graph[queue[0][queue[1][t]]][queue[0][t]]>0)
            {
                min=graph[queue[0][queue[1][t]]][queue[0][t]];
            }
            t=queue[1][t];
        }
        for(;qf>1;)
        {
            graph[queue[0][queue[1][qf]]][queue[0][qf]]-=min;
            graph[queue[0][qf]][queue[0][queue[1][qf]]]+=min;
            qf=queue[1][qf];
        }
        sum+=min;
    }
}

int main(int argc, char* argv[])
{
    int m;
    while(cin>>m>>n)
    {
        for(int i(1);i<=n;i++)
        {
            for(int j(1);j<=n;j++)
            {
                graph[i][j]=0;
            }
        }
        while(m--)
        {
            int i,j,k;
            cin>>i>>j>>k;
            graph[i][j]+=k;
        }
        cout<<maxflow()<<endl;
    }
    return 0;
}

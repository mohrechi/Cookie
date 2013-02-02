#include<stdio.h>
#include<queue>
#include<map>
#include<memory.h>
using namespace std;

int main()
{
    int n,m,t,caseNum=0;
    bool visit[1005];
    char s[20];
    while(scanf("%d",&n),n)
    {
        queue<int> q[1005],rank;
        map<int,int> team;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&t);
                team[t]=i;
            }
        }
        memset(visit,0,sizeof(visit));
        printf("Scenario #%d\n",++caseNum);
        while(scanf("%s",s),*s!='S')
        {
            if(*s=='E')
            {
                scanf("%d",&t);
                q[team[t]].push(t);
                if(visit[team[t]]==false)
                {
                    rank.push(team[t]);
                    visit[team[t]]=true;
                }
            }
            else
            {
                printf("%d\n",q[rank.front()].front());
                q[rank.front()].pop();
                if(q[rank.front()].empty())
                {
                    visit[rank.front()]=false;
                    rank.pop();
                }
            }
        }
        printf("\n");
    }
    return 0;
}

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
const int M=1005;
int t,n,len,num,sum;
char s[M];
int in[30],out[30],p,q;
bool g[30][30],vis[30],is[30];
void dfs(int x)
{
    vis[x]=1;
    num++;
    for(int i=0;i<26;i++)
        if(!vis[i]&&g[x][i])dfs(i);
}
bool judge()
{
    for(int i=0;i<26;i++)
    {
        num=0;
        memset(vis,0,sizeof(vis));
        dfs(i);
        if(num==sum)return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(g,0,sizeof(g));
        memset(is,0,sizeof(is));
         memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        scanf("%d",&n);
        sum=0;
        while(n--)
        {
            scanf("%s",s);
            len=strlen(s);
            in[s[0]-'a']++;
            out[s[len-1]-'a']++;
            g[s[0]-'a'][s[len-1]-'a']=1;
            if(!is[s[0]-'a'])
            {
                sum++;
                is[s[0]-'a']=1;
            }
            if(!is[s[len-1]-'a'])
            {
                sum++;
                is[s[len-1]-'a']=1;
            }
        }
        if(!judge())printf("The door cannot be opened.\n");
        else
        {
            p=q=0;
            for(int i=0;i<26;i++)
            {
                if(!in[i]&&!out[i])continue;
                if(abs(in[i]-out[i])==1)p++;
                if(in[i]-out[i]==0)q++;
            }
            if(p==2&&q==sum-2||sum==q)printf("Ordering is possible.\n");
            else
                 printf("The door cannot be opened.\n");
        }
    }
    return 0;
}

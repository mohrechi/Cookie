#include<stdio.h>
//#define METHOD1
#define METHOD2

#if defined(METHOD1)
int n,color,draw[30];
bool graph[30][30];

void dfs(int index, int colorNum)
{
    if(colorNum>=color)
    {
        return;
    }
    if(index==n)
    {
        color=colorNum;
        return;
    }
    for(int i=1;i<=colorNum;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            if(graph[index][j] and draw[j]==i)
            {
                break;
            }
        }
        if(j==n)
        {
            draw[index]=i;
            dfs(index+1,colorNum);
            draw[index]=0;
        }
    }
    draw[index]=++colorNum;
    dfs(index+1,colorNum);
    draw[index]=0;
}
#elif defined(METHOD2)
static const int V = 30;
int graph[V][V], dp[V], stk[V][V], mx;
int dfs(int n, int ns, int dep)
{
    if(0 == ns){
        if (dep > mx) mx = dep;
        return 1;
    }
    int i, j, k, p, cnt;
    for(i = 0; i < ns; i++){
        k = stk[dep][i];
        cnt = 0;
        if(dep + n - k <= mx) return 0;
        if(dep + dp[k] <= mx) return 0;
        for(j = i + 1; j < ns; j++){
            p = stk[dep][j];
            if(graph[k][p])
                stk[dep + 1][cnt++] = p;
        }
        dfs(n, cnt, dep + 1);
    }
    return 1;
}

int clique(int n)
{// vertex: 0 ~ n-1
    int i, j, ns;
    for (mx = 0, i = n - 1;i>= 0;i--) {
        for (ns = 0, j = i + 1; j < n; j++)
            if (graph[i][j])
                stk[1][ ns++ ] = j;
        dfs(n, ns, 1); dp[i] = mx;
    }
    return mx;
}
#endif

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                graph[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            while(getchar()!=':');
            char ch;
            while((ch=getchar())!='\n')
            {
                graph[i][ch-'A']=true;
            }
        }
        #if defined(METHOD1)
            for(int i=0;i<n;i++)
            {
                draw[i]=0;
            }
            color=0x7FFFFFFF;
            dfs(0,1);
        #elif defined(METHOD2)
            int color = clique(n);
        #endif
        if(1==color)
        {
            printf("1 channel needed.\n");
        }
        else
        {
            printf("%d channels needed.\n",color);
        }
    }
    return 0;
}

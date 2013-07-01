/*#include <cstdio>
#include <cstring>
static const int MAXN = 1001;
static const int MAXM = 501;

int n, m;
struct Edge
{
    int v, next;
}edge[MAXN*MAXM];
int edgeNumber, head[MAXN];
int groupSize;
bool visited[MAXN];
int number[MAXM];
int link[MAXM][MAXN];

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool find(int x)
{
    if(!visited[x])
    {
        visited[x] = true;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            if(number[edge[i].v] < groupSize)
            {
                link[edge[i].v][number[edge[i].v]++] = x;
                return true;
            }
            for(int j=0;j<groupSize;++j)
            {
                if(link[edge[i].v][j] == -1 || find(link[edge[i].v][j]))
                {
                    link[edge[i].v][j] = x;
                    return true;
                }
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    memset(number, 0, sizeof(number));
    memset(link, -1, sizeof(link));
    for(int i=0;i<n;++i)
    {
        memset(visited, false, sizeof(visited));
        if(find(i))
        {
            ++ ans;
        }
    }
    return ans;
}

int main()
{
    char s[20];
    int num;
    while(scanf("%d%d",&n,&m), n || m)
    {
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=0;i<n;++i)
        {
            while(scanf("%s ", s), *s == 0);
            bool flag = true;
            while(flag)
            {
                num = 0;
                char ch;
                while(true)
                {
                    scanf("%c", &ch);
                    if(ch >= '0' && ch <= '9')
                    {
                        num = num * 10 + ch - '0';
                    }
                    else if(ch == ' ' || ch == '\t')
                    {
                        break;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                addEdge(i, num);
            }
        }
        int ans;
        int left = 1, right = n;
        while(left <= right)
        {
            groupSize = (left + right) >> 1;
            if(hungary() >= n)
            {
                ans = groupSize;
                right = groupSize - 1;
            }
            else
            {
                left = groupSize + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<sstream>
using namespace std;
#define CLR(arr,val) memset(arr,val,sizeof(arr))
inline int ReadInt()
{
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9') ch = getchar();
    do{data = data*10 + ch-'0';ch = getchar();} while (ch >= '0' && ch <= '9');
    return data;
}
const int MaxV=1010,MaxE=1010*510,Max2=510;
template<int MaxV,int MaxE>
struct LinkGraph
{
    LinkGraph()
    {
        clear();
    }
    void clear()
    {
        CLR(Head,-1);
        top=0;
        CLR(Size,0);
    }
    void add(int u,int v)
    {
        ++Size[u];
        Num[top]=v;
        Next[top]=Head[u];
        Head[u]=top++;
    }
    int Head[MaxV],Next[MaxE],Num[MaxE],top;
    int Size[MaxV];
};

LinkGraph<MaxV,MaxE> g1;
LinkGraph<Max2,MaxE> g2;
bool used[Max2];
bool Augument(int u,int mx)
{
    for(int i=g1.Head[u];i!=-1;i=g1.Next[i])
    {
        if(!used[g1.Num[i]])
        {
            used[g1.Num[i]]=true;
            if(g2.Size[g1.Num[i]]<mx)
            {
                g2.add(g1.Num[i],u);
                return true;
            }
            for(int j=g2.Head[g1.Num[i]];j!=-1;j=g2.Next[j])
            {
                if(Augument(g2.Num[j],mx))
                {
                    g2.Num[j]=u;
                    return true;
                }
            }
        }
    }
    return false;
}

bool judge(int v1,int m)
{
    g2.clear();
    for(int i=0;i!=v1;i++)
    {
        CLR(used,0);
        if(!Augument(i,m))
            return false;
    }
    return true;
}
char str[20000];

int main()
{
    int m,n,v;
    while((m=ReadInt()) && (n=ReadInt()))
    {
        g1.clear();
        for(int i=0;i!=m;i++)
        {
            scanf("%*s");
            gets(str);
            stringstream ss(str);
            while(ss>>v)
            {
                g1.add(i,v);
            }
        }
        int beg=1,end=m,mid;
        while(beg<end)
        {
            mid=(beg+end)/2;
            if(judge(m,mid))
                end=mid;
            else
                beg=mid+1;
        }
        printf("%d\n",beg);
    }
}

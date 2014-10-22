#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 12;
const int MAXM = 1005;

int n, m;
bool visit[1<<MAXN];
int infect[MAXM<<1], infectNumber;
int link[MAXM<<1];

struct Edge
{
    int v, next;
}edge[MAXM * MAXM * 4];
int head[MAXM<<1], edgeNumber;

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

inline int getPosition(const char *str)
{
    int res = 0;
    for(int i=0;str[i];++i)
    {
        res <<= 1;
        if('1' == str[i])
        {
            res += 1;
        }
    }
    return res;
}

inline void setVisit(const char *str)
{
    visit[getPosition(str)] = true;
}

bool isConnect(const int &x, const int &y)
{
    int z = x ^ y;
    return 0 == (z && (z & (z - 1)));
}

bool find(int u)
{
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!visit[v])
        {
            visit[v] = true;
            if(-1 == link[v] || find(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(int i=0;i<infectNumber;++i)
    {
        memset(visit, false, sizeof(visit));
        if(find(i))
        {
            ++ ans;
        }
    }
    return ans;
}

int main()
{
    char buffer[MAXN];
    while(scanf("%d%d", &n, &m), n || m)
    {
        memset(visit, false, sizeof(visit));
        for(int i=0;i<m;++i)
        {
            scanf("%s", buffer);
            bool flag = true;
            for(int j=0;buffer[j];++j)
            {
                if('*' == buffer[j])
                {
                    flag = false;
                    buffer[j] = '0';
                    setVisit(buffer);
                    buffer[j] = '1';
                    setVisit(buffer);
                    break;
                }
            }
            if(flag)
            {
                setVisit(buffer);
            }
        }
        infectNumber = 0;
        for(int i=0;i<(1<<n);++i)
        {
            if(visit[i])
            {
                infect[infectNumber++] = i;
            }
        }
        clearEdge();
        for(int i=0;i<infectNumber;++i)
        {
            for(int j=i+1;j<infectNumber;++j)
            {
                if(isConnect(infect[i], infect[j]))
                {
                    addEdge(i, j);
                    addEdge(j, i);
                }
            }
        }
        printf("%d\n", infectNumber - (hungary() >> 1));
    }
    return 0;
}

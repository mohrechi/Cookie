#include <cstdio>
#include <cstring>
static const int MAXN = 500;

inline int abs(int x)
{
    return x>0?x:-x;
}

struct Book
{
    int hour, minute;
    int time, a, b, c, d;
    void input()
    {
        scanf("%d:%d%d%d%d%d",&hour,&minute,&a,&b,&c,&d);
        time = hour * 60 + minute;
    }
    bool reachable(const Book &bo) const
    {
        return time + abs(c-a) + abs(d-b) + abs(c-bo.a) + abs(d-bo.b) < bo.time;
    }
}book[MAXN];
int n;
bool graph[MAXN*2][MAXN*2], visited[MAXN*2];
int link[MAXN*2];

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        book[i].input();
    }
}

void init()
{
    memset(graph, false, sizeof(graph));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(book[i].reachable(book[j]))
            {
                graph[i][j+n] = true;
            }
        }
    }
}

bool find(int x)
{
    for(int i=0;i<n*2;++i)
    {
        if(graph[x][i] && !visited[i])
        {
            visited[i] = true;
            if(link[i] == -1 || find(link[i]))
            {
                link[i] = x;
                return true;
            }
        }
    }
    return false;
}

int hungray()
{
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(int i=0;i<n;++i)
    {
        memset(visited, false, sizeof(visited));
        if(find(i))
        {
            ++ans;
        }
    }
    return ans;
}

void output()
{
    printf("%d\n",n-hungray());
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        input();
        init();
        output();
    }
    return 0;
}

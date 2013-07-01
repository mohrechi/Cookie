#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define METHOD1 //Greedy 208KB 0MS
#define METHOD2 //Constraint WA
static const int MAXN = 10005;
static const int INF = 1000000000;
int n, ans;
#if defined(METHOD1)
struct Node
{
    int a, b;
}node[MAXN];

bool operator < (const Node &n1, const Node &n2)
{
    if(n1.b == n2.b)
    {
        return n1.a < n2.a;
    }
    return n1.b < n2.b;
}

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d%d",&node[i].a, &node[i].b);
    }
}

void solve()
{
    sort(node, node + n);
    int s = node[0].b - 1, t = node[0].b;
    ans = 2;
    for(int i=1;i<n;++i)
    {
        if(t < node[i].a)
        {
            ans += 2;
            s = node[i].b - 1;
            t = node[i].b;
        }
        else if(s < node[i].a || s > node[i].b)
        {
            ans += 1;
            s = t;
            t = node[i].b;
        }
    }
}
#elif defined(METHOD2)
struct Edge
{
    int t, next, length;
}edge[MAXN * 4];
int minV, maxV, edgeNumber;
int head[MAXN], queue[MAXN], dist[MAXN];
bool visited[MAXN];

void addEdge(int a, int b, int length)
{
    edge[edgeNumber].t = b;
    edge[edgeNumber].next = head[a];
    edge[edgeNumber].length = length;
    head[a] = edgeNumber++;
}

void input()
{
    int a,b;
    memset(head, -1, sizeof(head));
    scanf("%d",&n);
    minV = INF;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d", &a, &b);
        addEdge(a, b+1, 2);
        maxV = max(maxV, b+1);
        minV = min(minV, a);
    }
    for(int i=minV;i<=maxV;++i)
    {
        addEdge(i, i+1, 0);
        addEdge(i+1, i, -1);
    }
}

void solve()
{
    int front = 0, rear = 1;
    for(int i=minV;i<=maxV;++i)
    {
        dist[i] = - INF;
        visited[i] = false;
    }
    dist[minV] = 0;
    queue[front] = minV;
    while(front < rear)
    {
        int s = queue[front];
        visited[s] = false;
        for(int i=head[s];~i;i=edge[i].next)
        {
            int t = edge[i].t;
            if(dist[t] < dist[s] + edge[i].length)
            {
                dist[t] = dist[s] + edge[i].length;
                if(!visited[t])
                {
                    visited[t] = true;
                    queue[rear] = t;
                    if(++rear == MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        if(++front == MAXN)
        {
            front = 0;
        }
    }
    ans = dist[maxV] - dist[minV];
}

#endif

int main(int argc, char *argv[])
{
    input();
    solve();
    printf("%d\n", ans);
    return 0;
}

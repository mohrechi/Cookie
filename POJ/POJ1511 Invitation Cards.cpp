#include <cstdio>
#include <cstring>
static const int MAXN = 1000010;
static const long long INF = 0xFFFFFFFF;
struct Edge
{
    int u,v,w;
}edge[MAXN];
int stopNumber, edgeNumber;
int forwardMap[MAXN], reverseMap[MAXN];
int forward[MAXN], reverse[MAXN];
int queue[MAXN], front, rear;
long long ans;
long long dist[MAXN];
bool visited[MAXN];

void search(int map[], int next[])
{
    for(int i=1;i<=stopNumber;++i)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    front = 0, rear = 1;
    queue[0] = 1;
    dist[1] = 0;
    while(front < rear)
    {
        int t = queue[front];
        visited[t] = false;
        for(int i=map[t];i!=-1;i=next[i])
        {
            if(dist[edge[i].v] > dist[edge[i].u] + edge[i].w)
            {
                dist[edge[i].v] = dist[edge[i].u] + edge[i].w;
                if(!visited[edge[i].v])
                {
                    queue[rear] = edge[i].v;
                    if(++rear == MAXN)
                    {
                        rear = 0;
                    }
                    visited[edge[i].v] = true;
                }
            }
        }
        if(++front == MAXN)
        {
            front = 0;
        }
    }
    for(int i=1;i<=stopNumber;++i)
    {
        ans += dist[i];
    }
}

int main(int argc, char *argv[])
{
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d",&stopNumber,&edgeNumber);
        memset(forwardMap, -1, sizeof(forwardMap));
        memset(reverseMap, -1, sizeof(reverseMap));
        for(int i=0;i<edgeNumber;++i)
        {
            scanf("%d%d%d",&edge[i].u, &edge[i].v, &edge[i].w);
            forward[i] = forwardMap[edge[i].u];
            forwardMap[edge[i].u] = i;
            reverse[i] = reverseMap[edge[i].v];
            reverseMap[edge[i].v] = i;
        }
        ans = 0;
        search(forwardMap, forward);
        for(int i=0;i<edgeNumber;++i)
        {
            edge[i].u ^= edge[i].v;
            edge[i].v ^= edge[i].u;
            edge[i].u ^= edge[i].v;
        }
        search(reverseMap, reverse);
        printf("%lld\n", ans);
    }
    return 0;
}

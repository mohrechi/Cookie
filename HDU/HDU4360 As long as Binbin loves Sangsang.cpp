#include <cstdio>
#include <cstring>
const int MAXN = 1500;
const int MAXM = 30000;

int n, m;
struct Edge
{
    int v, w, id, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
__int64 ans, time;
__int64 dist[MAXN][4];
int queue[MAXN * 4][2];
int count[MAXN][4];
bool visit[MAXN][4];

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w, char id)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    edge[edgeNumber].id = id;
    head[u] = edgeNumber ++;
}

void solve()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<4;++j)
        {
            dist[i][j] = -1;
            visit[i][j] = false;
            count[i][j] = 0;
        }
    }
    int front = 0, rear = 0;
    for(int i=head[1];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        int id = edge[i].id;
        if(id == 0)
        {
            bool flag = false;
            if(dist[v][id] == -1)
            {
                dist[v][id] = w;
                flag = true;
            }
            else if(dist[v][id] > w)
            {
                dist[v][id] = w;
            }
            if(flag)
            {
                count[v][id] = 1;
                visit[v][id] = true;
                queue[rear][0] = v;
                queue[rear][1] = 0;
                ++ rear;
            }
        }
    }
    while(front != rear)
    {
        int u = queue[front][0];
        int s = queue[front][1];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            int id = edge[i].id;
            bool flag = false;
            if(id == (s + 1) % 4)
            {
                if(dist[v][id] == -1)
                {
                    dist[v][id] = dist[u][s] + w;
                    count[v][id] = count[u][s] + 1;
                    flag = true;
                }
                else if(dist[v][id] > dist[u][s] + w)
                {
                    dist[v][id] = dist[u][s] + w;
                    count[v][id] = count[u][s] + 1;
                    flag = true;
                }
                else if(dist[v][id] == dist[u][s] + w)
                {
                    if(count[v][id] < count[u][s] + 1)
                    {
                        count[v][id] = count[u][s] + 1;
                        flag = true;
                    }
                }
                if(flag && !visit[v][id])
                {
                    visit[v][id] = true;
                    queue[rear][0] = v;
                    queue[rear][1] = id;
                    if(++ rear >= MAXN * 4)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u][s] = false;
        if(++ front >= MAXN * 4)
        {
            front = 0;
        }
    }
    if(dist[n][3] == -1)
    {
        ans = -1;
    }
    else
    {
        ans = dist[n][3];
        time = count[n][3] / 4;
    }
}

int main()
{
    int caseNumber, u, v, w;
    char s[10], id;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d", &n, &m);
        clearEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%s", &u, &v, &w, s);
            switch(*s)
            {
                case 'L': id = 0; break;
                case 'O': id = 1; break;
                case 'V': id = 2; break;
                case 'E': id = 3; break;
            }
            addEdge(u, v, w, id);
            addEdge(v, u, w, id);
        }
        solve();
        printf("Case %d: ", cas);
        if(ans == -1 || m == 0)
        {
            printf("Binbin you disappoint Sangsang again, damn it!\n");
        }
        else
        {
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %I64d LOVE strings at last.\n", ans, time);
        }
    }
    return 0;
}

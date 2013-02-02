#include <cstdio>
#include <cstring>
static const int MAXH = 501;
static const int MAXW = 501;
static const int MAXN = 501;
static const int INF = 1000000000;

int height, width;
char map[MAXH][MAXW];
struct Position
{
    int x, y;
}house[MAXN], person[MAXN];
int houseNumber, personNumber;
struct Edge
{
    int u, v, flow, next, dist;
}edge[MAXN * MAXN * 2];
int edgeNumber;
int head[MAXN * 3];
int source, destination;

void addEdgeSub(int u, int v, int dist, int flow)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].dist = dist;
    edge[edgeNumber].flow = flow;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void addEdge(int u, int v, int dist, int flow)
{
    addEdgeSub(u, v, dist, flow);
    addEdgeSub(v, u, -dist, 0);
}

inline int abs(int x)
{
    return x > 0 ? x : -x;
}

int back[MAXN * 3];
int dist[MAXN * 3];
int queue[MAXN * 3];
int front, rear;
bool visited[MAXN];

bool findPath()
{
    memset(visited, false, sizeof(visited));
    for(int i=0;i<=destination;++i)
    {
        dist[i] = INF;
    }
    front = 0, rear = 1;
    queue[0] = source;
    dist[0] = 0;
    back[0] = -1;
    visited[0] = true;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(edge[i].flow > 0 && dist[v] > dist[u] + edge[i].dist)
            {
                dist[v] = dist[u] + edge[i].dist;
                back[v] = i;
                if(!visited[v])
                {
                    visited[v] = true;
                    queue[rear] = v;
                    if(++ rear >= MAXN * 3)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visited[u] = false;
        if(++ front >= MAXN * 3)
        {
            front = 0;
        }
    }
    return dist[destination] != INF;
}

int getMinimumCost()
{
    int ans = 0;
    while(findPath())
    {
        ans += dist[destination];
        int min = INF;
        int temp = destination;
        while(back[temp] != -1)
        {
            if(min > edge[back[temp]].flow)
            {
                min = edge[back[temp]].flow;
            }
            temp = edge[back[temp]].u;
        }
        temp = destination;
        while(back[temp] != -1)
        {
            edge[back[temp]].flow -= min;
            edge[back[temp]^1].flow += min;
            temp = edge[back[temp]].u;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d%d", &height, &width), height || width)
    {
        houseNumber = personNumber = 0;
        for(int i=0;i<height;++i)
        {
            scanf("%s", map[i]);
            for(int j=0;j<width;++j)
            {
                switch(map[i][j])
                {
                    case 'H':
                        ++ houseNumber;
                        house[houseNumber].x = i;
                        house[houseNumber].y = j;
                        break;
                    case 'm':
                        ++ personNumber;
                        person[personNumber].x = i;
                        person[personNumber].y = j;
                        break;
                }
            }
        }
        memset(head, -1, sizeof(head));
        edgeNumber = 0;
        source = 0, destination = (houseNumber<<1) + 1;
        for(int i=1;i<=personNumber;++i)
        {
            addEdge(source, i, 0, 1);
            addEdge(personNumber + i, destination, 0, 1);
            for(int j=1;j<=houseNumber;++j)
            {
                addEdge(i, personNumber + j, abs(house[j].x - person[i].x) + abs(house[j].y - person[i].y), 1);
            }
        }
        printf("%d\n", getMinimumCost());
    }
    return 0;
}

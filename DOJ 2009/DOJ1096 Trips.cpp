#include <cstdio>
#include <cstring>

int n;
int edge[1001][1001];
int sx[1001], sy[1001];
int dist[1001];

void search(int x, int forbid)
{
    for(int i=1;i<=edge[x][0];++i)
    {
        if(x == sx[forbid] && edge[x][i] == sy[forbid])
        {
            continue;
        }
        if(x == sy[forbid] && edge[x][i] == sx[forbid])
        {
            continue;
        }
        if(dist[edge[x][i]] == -1)
        {
            dist[edge[x][i]] = dist[x] + 1;
            search(edge[x][i], forbid);
        }
    }
}

int getTreeLength(int startPoint, int forbid)
{
    memset(dist, -1, sizeof(dist));
    dist[startPoint] = 0;
    search(startPoint, forbid);
    int max = 0;
    for(int i=1;i<=n;++i)
    {
        if(dist[i] > max)
        {
            startPoint = i;
            max = dist[i];
        }
    }
    memset(dist, -1, sizeof(dist));
    dist[startPoint] = 0;
    search(startPoint, forbid);
    max = 0;
    for(int i=1;i<=n;++i)
    {
        if(dist[i] > max)
        {
            max = dist[i];
        }
    }
    return max;
}

int main(int argc, char *argv[])
{
    while(~scanf("%d",&n))
    {
        memset(edge, 0, sizeof(edge));
        int x, y;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d", &x, &y);
            edge[x][++edge[x][0]] = y;
            edge[y][++edge[y][0]] = x;
            sx[i] = x, sy[i] = y;
        }
        int max = 0;
        for(int i=1;i<n;++i)
        {
            int temp = getTreeLength(sx[i], i) * getTreeLength(sy[i], i);
            if(temp > max)
            {
                max = temp;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}

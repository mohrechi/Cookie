#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 21;

bool graph[MAXN][MAXN];
int color[MAXN];
int vertexNumber, edgeNumber;
struct Node
{
    int index, degree;
    bool operator < (const Node &other) const
    {
        return degree > other.degree;
    }
}node[MAXN];

bool coloring(int colorNumber)
{
    memset(color, -1, sizeof(color));
    for(int i=0;i<colorNumber;++i)
    {
        for(int j=1;j<=vertexNumber;++j)
        {
            if(-1 == color[node[j].index])
            {
                int k;
                for(k=1;k<=vertexNumber;++k)
                {
                    if(graph[node[j].index][k] && color[k] == i)
                    {
                        break;
                    }
                }
                if(k > vertexNumber)
                {
                    color[node[j].index] = i;
                }
            }
        }
    }
    for(int i=1;i<=vertexNumber;++i)
    {
        if(-1 == color[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int u, v;
    while(~scanf("%d%d",&vertexNumber,&edgeNumber))
    {
        memset(graph, false, sizeof(graph));
        for(int i=1;i<=vertexNumber;++i)
        {
            node[i].index = i;
            node[i].degree = 0;
        }
        while(edgeNumber--)
        {
            scanf("%d%d",&u,&v);
            graph[u][v] = graph[v][u] = true;
            ++node[u].degree;
            ++node[v].degree;
        }
        sort(node + 1, node + vertexNumber + 1);
        int colorNumber;
        for(colorNumber=1;colorNumber<vertexNumber;++colorNumber)
        {
            if(coloring(colorNumber))
            {
                break;
            }
        }
        printf("%d\n", colorNumber);
    }
    return 0;
}

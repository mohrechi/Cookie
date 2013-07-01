#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
static const int MAXN = 55;
struct Node
{
    int x, y, w;
    bool operator < (const Node &node) const
    {
        return w > node.w;
    }
}node[MAXN*MAXN];
int nodeNumber, totalTime;

int main(int argc, char *argv[])
{
    int t,n,m,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&totalTime);
        nodeNumber = 0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d",&p);
                if(p)
                {
                    node[nodeNumber].x = i;
                    node[nodeNumber].y = j;
                    node[nodeNumber++].w = p;
                }
            }
        }
        sort(node, node + nodeNumber);
        int ans = 0;
        for(int i=0;i<nodeNumber;++i)
        {
            if(0 == i)
            {
                if(totalTime >= node[i].x + node[i].x + 1)
                {
                    ans += node[i].w;
                    totalTime -= node[i].x + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(totalTime >= abs(node[i].x - node[i-1].x) + abs(node[i].y - node[i-1].y) + 1 + node[i].x)
                {
                    ans += node[i].w;
                    totalTime -= abs(node[i].x - node[i-1].x) + abs(node[i].y - node[i-1].y) + 1;
                }
                else
                {
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

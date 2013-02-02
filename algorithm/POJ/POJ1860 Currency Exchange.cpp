#include <cstdio>
#include <cstring>
static const int MAXN = 205;
int n,m,s;
double v;
struct Edge
{
    int u, v;
    double r, c;
}edge[205];
double dist[MAXN];

void input()
{
    int a,b;
    double r1,c1,r2,c2;
    scanf("%d%d%d%lf",&n,&m,&s,&v);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%lf%lf%lf%lf",&a,&b,&r1,&c1,&r2,&c2);
        edge[i].u = a;
        edge[i].v = b;
        edge[i].r = r1;
        edge[i].c = c1;
        edge[i + m].u = b;
        edge[i + m].v = a;
        edge[i + m].r = r2;
        edge[i + m].c = c2;
    }
}

bool bellman()
{
    bool relax = true;
    memset(dist, 0, sizeof(dist));
    dist[s - 1] = v;
    m <<= 1;
    for(int i=0;i<n && relax;++i)
    {
        relax = false;
        for(int j=0;j<m;++j)
        {
            if(dist[edge[j].v - 1] < (dist[edge[j].u - 1] - edge[j].c) * edge[j].r)
            {
                dist[edge[j].v - 1] = (dist[edge[j].u - 1] - edge[j].c) * edge[j].r;
                relax = true;
            }
        }
    }
    return relax;
}

int main(int argc, char *argv[])
{
    input();
    if(bellman())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

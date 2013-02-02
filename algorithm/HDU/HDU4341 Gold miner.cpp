#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300;
const int MAXT = 40005;
const int INF = 1000000000;

struct Point
{
    int x, y, t, w;

    inline void input()
    {
        scanf("%d%d%d%d",&x,&y,&t,&w);
    }

    bool operator < (const Point &p) const
    {
        return x * x + y * y < p.x * p.x + p.y * p.y;
    }
}point[MAXN];
int n, t;
int pointSet[MAXN][MAXN], pointNum[MAXN], setNum;
int belong[MAXN];
int source, destination;

int operator * (const Point &a, const Point &b)
{
    return a.x * b.y - b.x * a.y;
}

int d[MAXT];

int main()
{
    int caseNumber = 0;
    while(~scanf("%d%d", &n, &t))
    {
        for(int i=0;i<n;++i)
        {
            point[i].input();
        }
        sort(point, point + n);
        memset(belong, -1, sizeof(belong));
        setNum = 0;
        for(int i=0;i<n;++i)
        {
            if(belong[i] == -1)
            {
                pointNum[setNum] = 1;
                pointSet[setNum][0] = i;
                belong[i] = setNum;
                for(int j=i+1;j<n;++j)
                {
                    if(belong[j] == -1)
                    {
                        if(point[i] * point[j] == 0)
                        {
                            pointSet[setNum][pointNum[setNum]++] = j;
                            belong[j] = setNum;
                        }
                    }
                }
                ++ setNum;
            }
        }
        memset(d, 0, sizeof(d));
        for(int i=0;i<setNum;++i)
        {
            for(int k=t;k>=0;--k)
            {
                int sumw = point[pointSet[i][0]].w;
                int sumt = point[pointSet[i][0]].t;
                for(int j=0;j<pointNum[i];++j)
                {
                    if(k >= sumt)
                    {
                        d[k] = max(d[k], d[k-sumt] + sumw);
                    }
                    sumw += point[pointSet[i][j+1]].w;
                    sumt += point[pointSet[i][j+1]].t;
                }
            }
        }
        printf("Case %d: %d\n", ++ caseNumber, d[t]);
    }
    return 0;
}

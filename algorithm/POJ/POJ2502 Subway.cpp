#include <cstdio>
#include <cstring>
#include <cmath>
static const int MAXN = 256;

struct Point
{
    int x, y;
    int input()
    {
        return scanf("%d%d",&x,&y);
    }
}pos[MAXN];
int posNumber;
double dist[MAXN][MAXN];

inline int square(int x)
{
    return x * x;
}

double distance(const Point &a, const Point &b)
{
    return sqrt((double)(square(a.x - b.x) + square(a.y - b.y)));
}

int main()
{
    for(int i=0;i<MAXN;++i)
        for(int j=0;j<MAXN;++j)
            dist[i][j] = -1.0;
    pos[0].input();
    pos[1].input();
    posNumber = 2;
    while(~pos[posNumber].input())
    {
        ++ posNumber;
        while(pos[posNumber].input(), pos[posNumber].x != -1 || pos[posNumber].y != -1)
        {
            dist[posNumber-1][posNumber] = dist[posNumber][posNumber-1] = distance(pos[posNumber-1], pos[posNumber]) / 40.0;
            ++ posNumber;
        }
    }
    double temp;
    for(int i=0;i<posNumber;++i)
        for(int j=i;j<posNumber;++j)
            if(temp = distance(pos[i], pos[j]) / 10.0, temp < dist[i][j] || dist[i][j] < 0.0)
                dist[i][j] = dist[j][i] = temp;
    for(int k=0;k<posNumber;++k)
        for(int i=0;i<posNumber;++i)
            for(int j=0;j<posNumber;++j)
                if(dist[i][k] > 0.0)
                    if(dist[k][j] > 0.0)
                        if(dist[i][j] > dist[i][k] + dist[k][j])
                            dist[i][j] = dist[i][k] + dist[k][j];
    printf("%.0lf\n", dist[0][1] * 60 / 1000);
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
const int MAXM = 505;

struct Player
{
    int speed, index, dist;
    bool boom;
    inline void input(int idx)
    {
        scanf("%d%d", &dist, &speed);
        index = idx;
        boom = false;
    }
}player[MAXN];

bool operator < (const Player &a, const Player &b)
{
    if(a.boom == b.boom)
    {
        if(a.dist == b.dist)
        {
            return a.index < b.index;
        }
        return a.dist > b.dist;
    }
    return a.boom < b.boom;
}

int main()
{
    int n, caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            player[i].input(i);
        }
        int maximum, index;
        printf("Case #%d:\n", cas);
        for(int i=1;i<MAXM && i<=n;++i)
        {
            maximum = -1;
            if(i == 1)
            {
                for(int j=1;j<=n;++j)
                {
                    if(player[j].dist > maximum)
                    {
                        maximum = player[j].dist;
                        index = j;
                    }
                }
                printf("%d", index);
            }
            else
            {
                for(int j=1;j<=n;++j)
                {
                    if(!player[j].boom)
                    {
                        player[j].dist += player[j].speed;
                        if(player[j].dist > maximum)
                        {
                            maximum = player[j].dist;
                            index = j;
                        }
                    }
                }
                printf(" %d", index);
            }
            player[index].boom = true;
        }
        sort(player + 1, player + 1 + n);
        for(int i=MAXM, j=1;i<=n;++i, ++j)
        {
            printf(" %d", player[j].index);
        }
        printf("\n");
    }
    return 0;
}

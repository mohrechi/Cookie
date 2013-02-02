#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 15;
const int MAXK = 505;
const int dirX[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dirY[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int r, c, x, y;
bool v[MAXN][MAXN];

int main()
{
    int tx, ty, type, k;
    while(~scanf("%d%d%d%d", &r, &c, &x, &y))
    {
        scanf("%d", &k);
        memset(v, true, sizeof(v));
        while(k--)
        {
            scanf("%d%d%d", &tx, &ty, &type);
            if(type == 0)
            {
                v[tx][ty] = false;
            }
            else
            {
                if(tx < x)
                {
                    ++ tx;
                }
                else if(tx > x)
                {
                    -- tx;
                }
                if(ty < y)
                {
                    ++ ty;
                }
                else if(ty > y)
                {
                    -- ty;
                }
                v[tx][ty] = false;
            }
        }
        bool flag = false;
        for(int k=0;k<9;++k)
        {
            tx = x + dirX[k];
            ty = y + dirY[k];
            if(tx >= 1 && tx <= r)
            {
                if(ty >= 1 && ty <= c)
                {
                    if(v[tx][ty])
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if(flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n;
struct Point
{
    int x, y;
} point[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            bool left = false;
            bool right = false;
            bool top = false;
            bool bottom = false;
            for(int j=0;j<n;++j)
            {
                if(point[i].y == point[j].y)
                {
                    if(point[i].x > point[j].x)
                    {
                        left = true;
                    }
                    else if(point[i].x < point[j].x)
                    {
                        right = true;
                    }
                }
                else if(point[i].x == point[j].x)
                {
                    if(point[i].y > point[j].y)
                    {
                        bottom = true;
                    }
                    else if(point[i].y < point[j].y)
                    {
                        top = true;
                    }
                }
            }
            if(left && right && top && bottom)
            {
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 1005;

double x, y, gx, gy, dx, dy;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    bool flag = false;
    scanf("%lf%lf%lf%lf", &gx, &gy, &dx, &dy);
    while(~scanf("%lf%lf",&x,&y))
    {
        if(!flag)
        {
            if(dist(x, y, gx, gy) * 2 < dist(x, y, dx, dy))
            {
                flag = true;
                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x, y);
            }
        }
    }
    if(!flag)
    {
        printf("The gopher cannot escape.\n");
    }
    return 0;
}

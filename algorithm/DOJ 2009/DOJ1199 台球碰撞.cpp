#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
const double INF = 1e100;

double L, W, x, y, R, a, v, s;
double vx, vy;

inline int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

inline double getTime(double pos, double edge, double speed)
{
    if(dblcmp(speed) == 0)
    {
        return INF;
    }
    if(speed > 0.0)
    {
        return ((edge - R) - pos) / speed;
    }
    return (R - pos) / speed;
}

inline double getXTime()
{
    return getTime(x, L, vx);
}

inline double getYTime()
{
    return getTime(y, W, vy);
}

inline void move(double time)
{
    x += vx * time;
    y += vy * time;
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &L, &W, &x, &y, &R, &a, &v, &s), dblcmp(L) || dblcmp(W) || dblcmp(x) || dblcmp(y) || dblcmp(R) || dblcmp(a) || dblcmp(v) || dblcmp(s))
    {
        vx = v * cos(a / 180.0 * PI);
        vy = v * sin(a / 180.0 * PI);
        while(true)
        {
            double tx = getXTime();
            double ty = getYTime();
            double tm = min(tx, ty);
            if(dblcmp(s - tm) <= 0)
            {
                move(s);
                break;
            }
            else
            {
                s -= tm;
                move(tm);
                int state = dblcmp(tx - ty);
                if(state == 0)
                {
                    vx = - vx;
                    vy = - vy;
                }
                else if(state == -1)
                {
                    vx = - vx;
                }
                else
                {
                    vy = - vy;
                }
            }
        }
        printf("%.2lf %.2lf\n", x, y);
    }
    return 0;
}

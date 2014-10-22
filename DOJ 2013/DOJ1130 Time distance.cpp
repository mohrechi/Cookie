#include <cstdio>
#include <algorithm>
using namespace std;

struct Time
{
    int h, m, s;
    int time;
    inline void input()
    {
        scanf("%d:%d:%d", &h, &m, &s);
        time = h * 3600 + m * 60 + s;
    }
} time1, time2;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        time1.input();
        time2.input();
        printf("%d\n", abs(time1.time - time2.time));
    }
    return 0;
}

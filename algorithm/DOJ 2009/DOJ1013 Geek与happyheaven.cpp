#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Time
{
    int h, m, s;
    int time;
    inline int getNumber(char c1, char c2)
    {
        return (c1 - '0') * 10 + c2 - '0';
    }
    inline void input()
    {
        char str[20];
        scanf("%s", str);
        h = getNumber(str[0], str[1]);
        m = getNumber(str[3], str[4]);
        s = getNumber(str[6], str[7]);
        time = h * 60 * 60 + m * 60 + s;
    }
    inline void printNumber(int x)
    {
        if(x < 10)
        {
            printf("0");
        }
        printf("%d", x);
    }
    inline void convert()
    {
        h = time / 3600;
        m = (time % 3600) / 60;
        s = time % 60;
    }
    inline void output()
    {
        printNumber(h);
        printf(":");
        printNumber(m);
        printf(":");
        printNumber(s);
        printf("\n");
    }
} s1, e1, s2, e2, ans;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        s1.input();
        e1.input();
        s2.input();
        e2.input();
        if(s2.time >= s1.time && s2.time < e1.time)
        {
            ans.time = min(e1.time, e2.time) - s2.time;
            ans.convert();
            ans.output();
        }
        else if(e2.time > s1.time && e2.time <= e1.time)
        {
            ans.time = e2.time - s1.time;
            ans.convert();
            ans.output();
        }
        else if(s1.time >= s2.time && s1.time < e2.time)
        {
            ans.time = e1.time - s1.time;
            ans.convert();
            ans.output();
        }
        else
        {
            printf("Impossible\n");
        }
    }
    return 0;
}

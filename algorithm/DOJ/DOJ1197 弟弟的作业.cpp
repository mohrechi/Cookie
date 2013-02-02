#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int ans = 0;
    int a, b, c;
    char s[100];
    while(~scanf("%s", s))
    {
        if(strstr(s, "?") != 0)
        {
            continue;
        }
        if(strstr(s, "+") != 0)
        {
            sscanf(s, "%d+%d=%d", &a, &b, &c);
            ans += a + b == c;
        }
        else
        {
            sscanf(s, "%d-%d=%d", &a, &b, &c);
            ans += a - b == c;
        }
    }
    printf("%d\n", ans);
    return 0;
}

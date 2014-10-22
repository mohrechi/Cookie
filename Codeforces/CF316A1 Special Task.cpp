#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char s[MAXN];
bool value[200];

int main()
{
    while (~scanf("%s", s))
    {
        int questionNum = 0;
        memset(value, false, sizeof(value));
        for (int i = 0; s[i]; ++i)
        {
            if (s[i] == '?')
            {
                ++questionNum;
            }
            else if (s[i] >= 'A' && s[i] <= 'J')
            {
                value[s[i]] = true;
            }
        }
        int alphaNum = 0;
        for (int i = 'A'; i <= 'J'; ++i)
        {
            alphaNum += value[i];
        }
        int ans = 1;
        for (int i = 0, j = 10; i < alphaNum; ++i, --j)
        {
            ans *= j;
        }
        if (s[0] == '?')
        {
            --questionNum;
            ans *= 9;
        }
        else if (s[0] >= 'A' && s[0] <= 'J')
        {
            ans = ans / 10 * 9;
        }
        printf("%d", ans);
        while (questionNum--)
        {
            putchar('0');
        }
        putchar('\n');
    }
    return 0;
}

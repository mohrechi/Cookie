#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans[32], ansNum;
char s[32], fold[32][32];

bool judge(int r)
{
    int c = 12 / r;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            fold[i][j] = s[i * c + j];
        }
    }
    for (int i = 0; i < c; ++i)
    {
        bool flag = true;
        for (int j = 0; j < r; ++j)
        {
            if (fold[j][i] != 'X')
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        ansNum = 0;
        for (int i = 1; i <= 12; ++i)
        {
            if (12 % i == 0)
            {
                if (judge(i))
                {
                    ans[ansNum++] = i;
                }
            }
        }
        printf("%d", ansNum);
        for (int i = 0; i < ansNum; ++i)
        {
            printf(" %dx%d", ans[i], 12 / ans[i]);
        }
        putchar('\n');
    }
    return 0;
}

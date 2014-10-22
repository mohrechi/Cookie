#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int num[2][10];
char digit[2][500];

int main()
{
    while (~scanf("%s%s", digit[0], digit[1]))
    {
        memset(num, 0, sizeof(num));
        for (int i = 0; digit[0][i]; ++i)
        {
            if (digit[0][i] == '9')
            {
                ++num[0][6];
            }
            else if (digit[0][i] == '5')
            {
                ++num[0][2];
            }
            else
            {
                ++num[0][digit[0][i] - '0'];
            }
        }
        for (int i = 0; digit[1][i]; ++i)
        {
            if (digit[1][i] == '9')
            {
                ++num[1][6];
            }
            else if (digit[1][i] == '5')
            {
                ++num[1][2];
            }
            else
            {
                ++num[1][digit[1][i] - '0'];
            }
        }
        int ans = 0x7fffffff;
        for (int i = 0; i < 9; ++i)
        {
            if (num[0][i])
            {
                ans = min(ans, num[1][i] / num[0][i]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n;
char str[MAXN];
int appear[MAXN];

int main()
{
    scanf("%d\n", &n);
    while (n--)
    {
        gets(str);
        memset(appear, 0, sizeof(appear));
        for (int i = 0; str[i]; ++i)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            ++appear[str[i]];
        }
        int index = 'A';
        for (int i = 'B'; i <= 'Z'; ++i)
        {
            if (appear[i] > appear[index])
            {
                index = i;
            }
        }
        bool flag = true;
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (appear[i] == appear[index] && i != index)
            {
                flag = false;
            }
        }
        if (flag)
        {
            int ans;
            for (int i = 0; i < 26; ++i)
            {
                if (((index - 'A') + i) % 26 == ('E' - 'A'))
                {
                    ans = i;
                    break;
                }
            }
            printf("%d ", (26 - ans) % 26);
            for (int i = 0; str[i]; ++i)
            {
                if (str[i] == ' ')
                {
                    putchar(' ');
                    continue;
                }
                putchar(((str[i] - 'A') + ans) % 26 + 'A');
            }
            putchar('\n');
        }
        else
        {
            printf("NOT POSSIBLE\n");
        }
    }
    return 0;
}

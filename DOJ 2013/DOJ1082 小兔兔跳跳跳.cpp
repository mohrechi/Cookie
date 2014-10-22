#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300005;

int n, k;
char road[MAXN];
int con[MAXN];

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        scanf("%s", road);
        for (int i = 0; i < n; ++i)
        {
            if (road[i] == '.')
            {
                con[i] = 0;
            }
            else
            {
                con[i] = con[i - 1] + 1;
            }
        }
        int count = 0;
        int end = 0;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            if (road[i] == '.')
            {
                ++count;
            }
            else
            {
                if (con[i] >= k)
                {
                    end = i;
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            printf("YES\n");
            if (count > 1000)
            {
                printf("Too much can be reach!\n");
            }
            else
            {
                bool space = false;
                for (int i = 0; i < n; ++i)
                {
                    if (road[i] == '.')
                    {
                        if (space)
                        {
                            putchar(' ');
                        }
                        else
                        {
                            space = true;
                        }
                        printf("%d", i + 1);
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("NO\n");
            if (count > 1000)
            {
                printf("Too much can be reach!\n");
            }
            else
            {
                bool space = false;
                for (int i = 0; i < end; ++i)
                {
                    if (road[i] == '.')
                    {
                        if (space)
                        {
                            putchar(' ');
                        }
                        else
                        {
                            space = true;
                        }
                        printf("%d", i + 1);
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}

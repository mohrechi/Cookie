#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    while (~scanf("%d", &n))
    {
        int len[6];
        int maxLen[6];
        for (int i = 1; i <= 5; ++i)
        {
            len[i] = 0;
            maxLen[i] = 0;
        }
        while (n--)
        {
            scanf("%d%d", &a, &b);
            for (int i = 1; i <= 5; ++i)
            {
                if (a == i || b == i)
                {
                    ++len[i];
                    maxLen[i] = max(maxLen[i], len[i]);
                }
                else
                {
                    len[i] = 0;
                }
            }
        }
        int index = 1;
        for (int i = 2; i <= 5; ++i)
        {
            if (maxLen[i] > maxLen[index])
            {
                index = i;
            }
        }
        printf("%d %d\n", maxLen[index], index);
    }
    return 0;
}

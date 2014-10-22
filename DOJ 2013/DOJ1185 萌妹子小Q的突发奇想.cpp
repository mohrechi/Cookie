#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;

int a[MAXN], b[MAXN];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + m);
        int sum = 0;
        int move = 0;
        for (int i = 0; i < n; ++i)
        {
            while (move < m - 1)
            {
                if (abs(a[i] - b[move]) >= abs(a[i] - b[move + 1]))
                {
                    ++move;
                }
                else
                {
                    break;
                }
            }
            sum += abs(a[i] - b[move]);
        }
        printf("%d\n", sum);
    }
    return 0;
}

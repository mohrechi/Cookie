#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 40;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, num[MAXN];
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &num[i]);
        }
        bool ans = false;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (num[i] == 0)
            {
                break;
            }
            ++cnt;
        }
        if (cnt & 1)
        {
            ans = true;
        }
        else
        {
            cnt = 0;
            for (int i = n - 1; i >= 0; --i)
            {
                if (num[i] == 0)
                {
                    break;
                }
                ++cnt;
            }
            if (cnt & 1)
            {
                ans = true;
            }
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}

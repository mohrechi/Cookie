#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int getSG(int k)
{
    if ((k & 3) == 1 || (k & 3) == 2)
    {
        return k;
    }
    if (k & 3)
    {
        return k + 1;
    }
    return k - 1;
}

int main()
{
    int T, n, a, s;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        s = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            s ^= getSG(a);
        }
        printf("%s\n", s ? "Alice" : "Bob");
    }
    return 0;
}

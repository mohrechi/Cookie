#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int x, k, d, a, b;
    scanf("%d%d", &x, &k);
    set<int> s;
    s.insert(x);
    while (k--)
    {
        scanf("%d", &d);
        if (d == 1)
        {
            scanf("%d%d", &a, &b);
            s.insert(a);
            s.insert(b);
        }
        else
        {
            scanf("%d", &a);
            s.insert(a);
        }
    }
    int last = 0;
    int min = 0, max = 0;
    for (auto i : s)
    {
        min += (i - last) >> 1;
        max += i - last - 1;
        last = i;
    }
    printf("%d %d\n", min, max);
    return 0;
}

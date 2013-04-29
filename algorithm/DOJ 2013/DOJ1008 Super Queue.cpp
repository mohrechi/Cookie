#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, op, x;
    while (~scanf("%d", &n))
    {
        queue<int> q;
        map<int, int> m;
        set<int> s;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &op);
            if (op == 1)
            {
                scanf("%d", &x);
                if (m[x] == 0)
                {
                    s.insert(x);
                }
                ++m[x];
                q.push(x);
            }
            else if (op == 2)
            {
                x = q.front();
                printf("%d\n", x);
                if (m[x] == 1)
                {
                    s.erase(x);
                }
                --m[x];
                q.pop();
            }
            else if (op == 3)
            {
                printf("%d\n", *s.rbegin());
            }
            else
            {
                printf("%d\n", *s.begin());
            }
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int main()
{
    int n, q, a;
    while(scanf("%d%d", &n, &q), n || q)
    {
        set<int> s;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            s.insert(a);
        }
        for(int i=0;i<q;++i)
        {
            scanf("%d", &a);
            if(s.find(a) == s.end())
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }
    return 0;
}

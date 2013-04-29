#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a;
    while(scanf("%d", &n), n + 1)
    {
        set<int> s;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            s.insert(a);
        }
        scanf("%d", &m);
        for(int i=0;i<m;++i)
        {
            scanf("%d", &a);
            if(s.find(a) != s.end())
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        printf("\n");
    }
    return 0;
}

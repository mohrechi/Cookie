#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n, m;
int a[MAXN];

int main()
{
    int k;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        priority_queue<int> q;
        scanf("%d", &m);
        int last = 1, cur;
        for(int i=0;i<m;++i)
        {
            scanf("%d", &cur);
            for(;last<=cur;++last)
            {
                q.push(a[last]);
            }
            if(i)
            {
                printf(" ");
            }
            printf("%d", q.top());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}

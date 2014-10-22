#include <cstdio>
#include <queue>
using namespace std;
static const int MAXN = 100005;
int t,c,a[MAXN];
int main(int argc, char *argv[])
{
    while(~scanf("%d%d",&t,&c))
    {
        for(int i=1;i<=t;++i)
        {
            scanf("%d",&a[i]);
        }
        int ans = 0;
        priority_queue<int> q;
        for(int i=t;i>=c;)
        {
            for(int j=0;j<c;++j)
            {
                if(i>=c)
                {
                    q.push(a[i]);
                    if(i%c == 0)
                    {
                        -- i;
                        break;
                    }
                }
                else
                {
                    break;
                }
                -- i;
            }
            ans += q.top();
            q.pop();
        }
        printf("%d\n", ans);
    }
    return 0;
}

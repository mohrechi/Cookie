#include <cstdio>
#include <cstring>
static const int MAXN = 1001;
int n;
int a[MAXN];
bool visited[MAXN];

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

inline int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        memset(visited, false, sizeof(visited));
        int ans = 1;
        for(int i=1;i<=n;++i)
        {
            if(!visited[i])
            {
                int temp = a[i];
                int count = 1;
                while(temp != i)
                {
                    visited[temp] = true;
                    temp = a[temp];
                    ++ count;
                }
                ans = lcm(ans, count);
            }
        }
        printf("%d\n", ans);
    }
}

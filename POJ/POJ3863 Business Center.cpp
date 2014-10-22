#include <cstdio>

int main()
{
    int n, m, u, d;
    int ans, temp;
    int left, right, mid;
    while(~scanf("%d%d",&n,&m))
    {
        ans = 0x7FFFFFFF;
        while(m--)
        {
            scanf("%d%d",&u,&d);
            left = 0, right = n;
            while(left <= right)
            {
                mid = (left + right) >> 1;
                temp = u * mid - d * (n - mid);
                if(temp <= 0)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                    if(temp < ans)
                    {
                        ans = temp;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

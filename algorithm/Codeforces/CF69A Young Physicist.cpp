#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, sum[3], v[3];
    while(~scanf("%d", &n))
    {
        memset(sum, 0, sizeof(sum));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<3;++j)
            {
                scanf("%d", &v[j]);
                sum[j] += v[j];
            }
        }
        if(sum[0] || sum[1] || sum[2])
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, m;
int a[MAXN][MAXN];

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=n-1;j>=0;--j)
            {
                if(j != n - 1)
                {
                    printf(" ");
                }
                printf("%d", a[j][i]);
            }
            printf("\n");
        }
    }
    return 0;
}

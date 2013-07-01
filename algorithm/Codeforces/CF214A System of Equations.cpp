#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        for(int i=0;i<=1000;++i)
        {
            for(int j=0;j<=1000;++j)
            {
                if(i * i + j == n && i + j * j == m)
                {
                    ++ ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

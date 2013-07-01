#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        bool flag = true;
        while(flag)
        {
            for(int i=1;i<=n;++i)
            {
                if(m >= i)
                {
                    m -= i;
                }
                else
                {
                    printf("%d\n", m);
                    flag = false;
                    break;
                }
            }
        }
    }
    return 0;
}

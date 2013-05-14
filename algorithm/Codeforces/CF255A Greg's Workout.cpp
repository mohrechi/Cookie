#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 25;

int main()
{
    int n, a, b[3];
    while(~scanf("%d", &n))
    {
        memset(b, 0, sizeof(b));
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            b[i%3] += a;
        }
        if(b[0] >= b[1] && b[0] >= b[2])
        {
            printf("chest\n");
        }
        else
        {
            if(b[1] >= b[2])
            {
                printf("biceps\n");
            }
            else
            {
                printf("back\n");
            }
        }
    }
    return 0;
}

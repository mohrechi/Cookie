#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, n;
    while(~scanf("%d%d%d", &a, &b, &n))
    {
        -- n;
        bool flag = false;
        for(int i=0;i<10;++i)
        {
            if((a * 10 + i) % b == 0)
            {
                a = a * 10 + i;
                flag = true;
                break;
            }
        }
        if(flag)
        {
            printf("%d", a);
            for(int i=0;i<n;++i)
            {
                printf("0");
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}

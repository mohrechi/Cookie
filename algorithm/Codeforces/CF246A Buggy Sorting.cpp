#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n <= 2)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=n;i>=1;--i)
            {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    return 0;
}

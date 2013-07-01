#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        if(n & 1)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=1;i<n;i+=2)
            {
                printf("%d %d ", i + 1, i);
            }
            printf("\n");
        }
    }
    return 0;
}

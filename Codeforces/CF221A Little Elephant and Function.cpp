#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d", n);
        for(int i=1;i<n;++i)
        {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}

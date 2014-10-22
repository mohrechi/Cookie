#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int n2 = 0, n5 = 0;
        for(int i=2;i<=n;i*=2)
        {
            n2 += n / i;
        }
        for(int i=5;i<=n;i*=5)
        {
            n5 += n / i;
        }
        printf("%d\n", min(n2, n5));
    }
    return 0;
}

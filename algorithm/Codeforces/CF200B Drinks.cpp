#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, p;
    while(~scanf("%d", &n))
    {
        int sum = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &p);
            sum += p;
        }
        printf("%lf\n", 1.0 * sum / n);
    }
    return 0;
}

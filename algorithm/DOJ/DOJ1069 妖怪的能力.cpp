#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    while(scanf("%d", &n), n)
    {
        int ma = 0;
        int mi = 100;
        int sum = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            ma = max(ma, a);
            mi = min(mi, a);
            sum += a;
        }
        sum -= ma + mi;
        printf("%.2lf\n", 1.0 * sum / (n - 2));
    }
    return 0;
}

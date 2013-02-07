#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, maxValue, minValue;
    while(~scanf("%d", &n))
    {
        int ans = 0;
        scanf("%d", &a);
        maxValue = minValue = a;
        for(int i=1;i<n;++i)
        {
            scanf("%d", &a);
            if(a > maxValue)
            {
                maxValue = a;
                ++ ans;
            }
            else if(a < minValue)
            {
                minValue = a;
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

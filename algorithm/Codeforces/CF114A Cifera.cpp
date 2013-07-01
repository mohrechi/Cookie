#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int k, l;
    while(~scanf("%d%d", &k, &l))
    {
        int num = 0;
        while(l > k && (l % k == 0))
        {
            l /= k;
            ++ num;
        }
        if(l == k)
        {
            printf("YES\n%d\n", num);
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

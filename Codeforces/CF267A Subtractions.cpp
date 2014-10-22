#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    scanf("%d", &n);
    while(n--)
    {
        long long sum = 0;
        scanf("%d%d", &a, &b);
        while(true)
        {
            if(a < b)
            {
                swap(a, b);
            }
            if(b == 0)
            {
                break;
            }
            sum += a / b;
            a %= b;
        }
        printf("%I64d\n", sum);
    }
    return 0;
}

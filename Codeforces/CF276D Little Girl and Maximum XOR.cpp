#include <cstdio>
#include <cstring>

int main()
{
    long long l, r;
    while(~scanf("%I64d%I64d", &l, &r))
    {
        long long bit;
        long long ans = 0;
        for(bit = 1; bit <= r; bit <<= 1)
        {
            if(r / bit > l / bit)
            {
                ans |= bit;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        bool flag = true;
        for(int i=1;i<=n && flag;++i)
        {
            int l = 1, r = n;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                long long sum = (long long)(i + (i + mid - 1)) * mid / 2;
                if(sum == n)
                {
                    flag = false;
                    for(int j=0;j<mid;++j)
                    {
                        if(j)
                        {
                            printf(" ");
                        }
                        printf("%d", i + j);
                    }
                    printf("\n");
                    break;
                }
                else if(sum > n)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
    }
    return 0;
}

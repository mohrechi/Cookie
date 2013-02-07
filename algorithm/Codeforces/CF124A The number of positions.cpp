#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    while(~scanf("%d%d%d", &n, &a, &b))
    {
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            int front = i;
            int back = n - i - 1;
            if(front >= a && back <= b)
            {
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

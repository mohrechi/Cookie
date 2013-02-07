#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        int num = min(n, m) + 1;
        printf("%d\n", num);
        for(int i=0;i<num;++i)
        {
            printf("%d %d\n", i, num - i - 1);
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[20];
    a[0] = 1;
    for(int i=1;i<20;++i)
    {
        a[i] = i * a[i - 1] + 1;
    }
    while(scanf("%d", &n), n + 1)
    {
        printf("%d\n", a[n]);
    }
    return 0;
}

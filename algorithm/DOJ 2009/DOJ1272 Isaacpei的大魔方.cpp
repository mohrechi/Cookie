#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d", &m);
    while(m--)
    {
        scanf("%d", &n);
        printf("%d\n", n * n * 6);
    }
    return 0;
}

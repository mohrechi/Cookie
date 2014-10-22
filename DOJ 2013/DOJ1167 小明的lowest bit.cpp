#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T, a;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &a);
        printf("%d\n", a & (-a));
    }
    return 0;
}

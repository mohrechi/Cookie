#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        int ans = 2100000000;
        int n, a, b;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &a, &b);
            ans = min(ans, a * b);
        }
        printf("%d\n", ans);
    }
    return 0;
}

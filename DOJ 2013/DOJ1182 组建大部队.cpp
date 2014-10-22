#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20;

int main()
{
    int n, num[MAXN];
    int caseNum = 0;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &num[i]);
        }
        sort(num + 1, num + n + 1);
        long long sum = 0;
        long long valid = 1;
        for (int i = n; i >= 1; --i)
        {
            sum += valid;
            valid *= num[i];
        }
        printf("Case %d: %lld\n", ++caseNum, sum + valid);
    }
    return 0;
}

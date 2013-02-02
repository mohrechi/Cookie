#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int caseNumber;
    int n, m, dmin, d;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<m;++i)
        {
            scanf("%d", &d);
            if(i)
            {
                dmin = min(dmin, d);
            }
            else
            {
                dmin = d;
            }
        }
        n /= dmin;
        printf("Case #%d: ", cas);
        if(n & 1)
        {
            printf("Bob\n");
        }
        else
        {
            printf("Alice\n");
        }
    }
    return 0;
}

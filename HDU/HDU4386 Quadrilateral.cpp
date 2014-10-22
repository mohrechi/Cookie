#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int edge[4];

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        for(int i=0;i<4;++i)
        {
            scanf("%d", &edge[i]);
        }
        printf("Case %d: ", cas);
        sort(edge, edge + 4);
        if(edge[0] + edge[1] + edge[2] <= edge[3])
        {
            printf("-1\n");
            continue;
        }
        double sum = 0.0;
        for(int i=0;i<4;++i)
        {
            sum += edge[i];
        }
        sum *= 0.5;
        double ans = 1.0;
        for(int i=0;i<4;++i)
        {
            ans *= sum - edge[i];
        }
        ans = sqrt(ans);
        printf("%.6lf\n", ans);
    }
    return 0;
}

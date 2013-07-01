#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int card[60];
int pos[60];

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        for(int i=1;i<=52;++i)
        {
            scanf("%d", &card[i]);
        }
        int n, l, r;
        scanf("%d%d%d",&n,&l,&r);
        int start = 1, cur = 1;
        pos[0] = 1;
        for(int i=1;i<=n;++i)
        {
            if(cur < l)
            {
                cur += r - l + 1;
            }
            else
            {
                cur = cur - l + 1;
            }
            pos[i] = cur;
            if(cur == 1)
            {
                start = pos[n % i];
                break;
            }
            start = cur;
        }
        printf("Case #%d:", cas);
        if(start == 1)
        {
            for(int i=1;i<=52;++i)
            {
                printf(" %d", card[i]);
            }
        }
        else
        {
            for(int i=1;i<start;++i)
            {
                printf(" %d", card[r - start + 1 + i]);
            }
            for(int i=1;i<=r-start+1;++i)
            {
                printf(" %d", card[i]);
            }
            for(int i=r+1;i<=52;++i)
            {
                printf(" %d", card[i]);
            }
        }
        printf("\n");
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node
{
    int index, sum;
} black[MAXN], white[MAXN];
int blackNum, whiteNum;

int main()
{
    int n, color;
    while(~scanf("%d", &n))
    {
        blackNum = whiteNum = 0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &color);
            if(color)
            {
                black[blackNum].index = i;
                scanf("%d", &black[blackNum].sum);
                ++ blackNum;
            }
            else
            {
                white[whiteNum].index = i;
                scanf("%d", &white[whiteNum].sum);
                ++ whiteNum;
            }
        }
        for(int i=0,j=0;j<whiteNum;)
        {
            for(;black[i].sum>=0&&j<whiteNum;++j)
            {
                if(black[i].sum >= white[j].sum)
                {
                    printf("%d %d %d\n", black[i].index, white[j].index, white[j].sum);
                    black[i].sum -= white[j].sum;
                }
                else
                {
                    printf("%d %d %d\n", black[i].index, white[j].index, black[i].sum);
                    white[j].sum -= black[i].sum;
                    black[i].sum = -1;
                }
            }
            ++ i, -- j;
            for(;white[j].sum>=0&&i<blackNum;++i)
            {
                if(white[j].sum >= black[i].sum)
                {
                    printf("%d %d %d\n", white[j].index, black[i].index, black[i].sum);
                    white[j].sum -= black[i].sum;
                }
                else
                {
                    printf("%d %d %d\n", white[j].index, black[i].index, white[j].sum);
                    black[i].sum -= white[j].sum;
                    white[j].sum = -1;
                }
            }
            --i, ++ j;
        }
    }
    return 0;
}

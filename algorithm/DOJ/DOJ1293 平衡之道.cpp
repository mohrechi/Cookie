#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int sumW[MAXN][MAXN];
int sumB[MAXN][MAXN];
char map[MAXN][MAXN];
bool same[MAXN][MAXN];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        memset(sumB, 0, sizeof(sumB));
        memset(sumW, 0, sizeof(sumW));
        memset(same, false, sizeof(same));
        for(int i=1;i<=n;++i)
        {
            scanf("%s", map[i] + 1);
            for(int j=1;j<=m;++j)
            {
                sumW[i][j] = sumW[i][j - 1] + (map[i][j] == 'w');
                sumB[i][j] = sumB[i][j - 1] + (map[i][j] == 'b');
            }
            for(int j=1;j<=m;++j)
            {
                sumW[i][j] += sumW[i - 1][j];
                sumB[i][j] += sumB[i - 1][j];
                same[i][j] = sumW[i][j] == sumB[i][j];
            }
        }
        int ans = 0;
        for(int ii=n;ii>=1;--ii)
        {
            for(int jj=m;jj>=1;--jj)
            {
                if(ii * jj <= ans)
                {
                    continue;
                }
                for(int i=1;i+ii-1<=n;++i)
                {
                    for(int j=1;j+jj-1<=m;++j)
                    {
                        int numW = sumW[i+ii-1][j+jj-1] - sumW[i-1][j+jj-1] - sumW[i+ii-1][j-1] + sumW[i-1][j-1];
                        int numB = sumB[i+ii-1][j+jj-1] - sumB[i-1][j+jj-1] - sumB[i+ii-1][j-1] + sumB[i-1][j-1];
                        if(numW == numB)
                        {
                            ans = ii * jj;
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

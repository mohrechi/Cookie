#include <cstdio>
#include <cstring>
static const int MAXN = 300;

char num[MAXN][MAXN];
int len[MAXN];

void output(int x)
{
    for(int i=len[x]-1;i>=0;--i)
    {
        printf("%d",num[x][i]);
    }
    printf("\n");
}

int main()
{
    num[0][0] = num[1][0] = 1;
    len[0] = len[1] = 1;
    for(int i=2;i<MAXN;++i)
    {
        for(int j=0;j<len[i-1];++j)
        {
            num[i][j] += num[i-1][j] + num[i-2][j] * 2;
            if(num[i][j] >= 10)
            {
                num[i][j+1] = num[i][j] / 10;
                num[i][j] %= 10;
            }
        }
        if(num[i][len[i-1]] > 0)
        {
            len[i] = len[i-1] + 1;
        }
        else
        {
            len[i] = len[i-1];
        }
    }
    int n;
    while(~scanf("%d", &n))
    {
        output(n);
    }
    return 0;
}

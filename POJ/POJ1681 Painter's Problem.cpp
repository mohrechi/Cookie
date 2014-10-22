#include <cstdio>
#include <cstring>
const int MAXN = 20;
const int MAXM = MAXN * MAXN;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

char grid[MAXN][MAXN];
int t, n;
int a[MAXM][MAXM];

inline int abs(int x)
{
    return x >= 0 ? x : -x;
}

inline void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

inline int getPos(int i, int j)
{
    return i * n + j;
}

int gauss(int r, int c)
{
    int i = 0;
    for(int j=0;j<c;++j)
    {
        int index = i;
        for(int k=i+1;k<r;++k)
        {
            if(abs(a[k][j]) > abs(a[index][j]))
            {
                index = k;
            }
        }
        if(a[index][j] != 0)
        {
            for(int k=j;k<=c;++k)
            {
                swap(a[index][k], a[i][k]);
            }
            for(int k=i+1;k<r;++k)
            {
                if(a[k][j] != 0)
                {
                    for(int l=j;l<=c;++l)
                    {
                        a[k][l] ^= a[i][l];
                    }
                }
            }
            ++ i;
        }
    }
    for(int j=i;j<r;++j)
    {
        if(a[j][c])
        {
            return -1;
        }
    }
    int cnt = a[r-1][c];
    for(i=r-2;i>=0;--i)
    {
        for(int j=i+1;j<r;++j)
        {
            a[i][c] ^= (a[i][j] & a[j][c]);
        }
        cnt += a[i][c];
    }
    return cnt;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i=0;i<n;++i)
        {
            scanf("%s", grid[i]);
            for(int j=0;j<n;++j)
            {
                a[getPos(i, j)][getPos(i, j)] = 1;
                for(int k=0;k<4;++k)
                {
                    int tx = i + dirX[k];
                    int ty = j + dirY[k];
                    if(tx >= 0 && tx < n)
                    {
                        if(ty >= 0 && ty < n)
                        {
                            a[getPos(tx, ty)][getPos(i, j)] = 1;
                        }
                    }
                }
                a[getPos(i, j)][n*n] = (grid[i][j] == 'w');
            }
        }
        int ans = gauss(n * n, n * n);
        if(ans == -1)
        {
            printf("inf\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}

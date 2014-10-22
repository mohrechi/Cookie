#include <cstdio>
#include <cstring>
static const int MAXN = 105;

bool rs[MAXN], cs[MAXN], m[MAXN][MAXN];
int n, orn, ocn, rp, cp;

int main()
{
    while(scanf("%d", &n), n)
    {
        memset(rs, 0, sizeof(rs));
        memset(cs, 0, sizeof(cs));
        orn = 0, ocn = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &m[i][j]);
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                rs[i] ^= m[i][j];
                cs[i] ^= m[j][i];
            }
        }
        for(int i=0;i<n;++i)
        {
            if(rs[i])
            {
                ++orn;
                rp = i;
            }
            if(cs[i])
            {
                ++ocn;
                cp = i;
            }
        }
        if(orn == 0 && ocn == 0)
        {
            printf("OK\n");
        }
        else if(orn == 1 && ocn == 1)
        {
            printf("Change bit (%d,%d)\n", rp+1, cp+1);
        }
        else
        {
            printf("Corrupt\n");
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>

int main()
{
    int s, d, e[12], ans;
    int n = 1 << 12;
    while(~scanf("%d%d",&s,&d))
    {
        ans = -1;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<12;++j)
            {
                e[j] = (i&(1<<j))?s:-d;
            }
            bool flag = true;
            for(int j=0;j<8;++j)
            {
                int cnt = 0;
                for(int k=0;k<5;++k)
                {
                    cnt += e[j+k];
                }
                if(cnt >= 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                int cnt = 0;
                for(int j=0;j<12;++j)
                {
                    cnt += e[j];
                }
                if(cnt > ans)
                {
                    ans = cnt;
                }
            }
        }
        if(ans >= 0)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("Deficit\n");
        }
    }
    return 0;
}

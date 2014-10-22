#include <cstdio>
#include <cstring>

int n;
char s[1000];
char ss[80][100], ssn;
char r[8][10];

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", s);
        for(int i=0;i<8;++i)
        {
            for(int j=0;j<8;++j)
            {
                r[i][j] = '0';
            }
            r[i][4] = 0;
        }
        ssn = 0;
        int li = 0;
        for(int i=0;;++i)
        {
            if(s[i] == ':' || s[i] == 0)
            {
                for(int j=li;j<i;++j)
                {
                    ss[ssn][j-li] = s[j];
                }
                ss[ssn++][i-li] = 0;
                li = i + 1;
                if(s[i] == 0)
                {
                    break;
                }
            }
        }
        for(int i=0;i<ssn;++i)
        {
            int len = strlen(ss[i]);
            if(len == 0)
            {
                break;
            }
            int sj = 4 - len;
            for(int j=sj;j<4;++j)
            {
                r[i][j] = ss[i][j-sj];
            }
        }
        for(int k=0,i=ssn-1;i>=0;--i,++k)
        {
            int len = strlen(ss[i]);
            if(len == 0)
            {
                break;
            }
            int sj = 4 - len;
            for(int j=sj;j<4;++j)
            {
                r[8-k-1][j] = ss[i][j-sj];
            }
        }
        for(int i=0;i<8;++i)
        {
            if(i)
            {
                printf(":");
            }
            printf("%s",r[i]);
        }
        printf("\n");
    }
    return 0;
}

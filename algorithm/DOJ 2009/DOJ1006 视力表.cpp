#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char map[4][3][3] =
{
    {
        {' ', '*', ' '},
        {' ', '*', ' '},
        {'*', '*', '*'}
    },
    {
        {'*', '*', '*'},
        {' ', '*', ' '},
        {' ', '*', ' '}
    },
    {
        {' ', ' ', '*'},
        {'*', '*', '*'},
        {' ', ' ', '*'}
    },
    {
        {'*', ' ', ' '},
        {'*', '*', '*'},
        {'*', ' ', ' '}
    }
};

char a[15][15];

int main()
{
    int t, n, m;
    scanf("%d", &t);
    for(int c=1;c<=t;++c)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;++i)
        {
            scanf("%s", &a[i]);
            for(int j=0;j<m;++j)
            {
                a[i][j] -= '0';
            }
        }
        printf("Case %d :\n", c);
        for(int i=0;i<n;++i)
        {
            for(int k=0;k<3;++k)
            {
                for(int j=0;j<m;++j)
                {
                    if(j)
                    {
                        printf(" ");
                    }
                    for(int l=0;l<3;++l)
                    {
                        printf("%c", map[a[i][j]][k][l]);
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}

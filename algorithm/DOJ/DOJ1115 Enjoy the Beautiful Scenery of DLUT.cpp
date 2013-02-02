#include <cstdio>
static const int MAXN = 1005;

int n;
char op[MAXN][MAXN];

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s",op[i]);
        }
        int dir = 0;
        int x = 0;
        int y = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;op[i][j];++j)
            {
                switch(op[i][j])
                {
                    case 'S':
                        dir %= 4;
                        switch(dir)
                        {
                            case 0: -- x; break;
                            case 1: ++ y; break;
                            case 2: ++ x; break;
                            case 3: -- y; break;
                        }
                        break;
                    case 'L':
                        dir += 3;
                        break;
                    case 'R':
                        ++ dir;
                        break;
                }
            }
        }
        dir %= 4;
        if((x == 0 && y == 0) || dir != 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

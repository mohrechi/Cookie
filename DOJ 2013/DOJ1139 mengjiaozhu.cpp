#include <cstdio>

enum Status
{
    STATUS_NO,
    STATUS_OOPS,
    STATUS_SUCCESS
} status;

int n, m;
char maze[20][20];
char op[200];

void test(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        status = STATUS_SUCCESS;
    }
    else if (maze[x][y] == '#')
    {
        status = STATUS_OOPS;
    }
}

int main()
{
    int x, y;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", maze[i] + 1);
            for (int j = 1; j <= m; ++j)
            {
                if (maze[i][j] == 'S')
                {
                    x = i;
                    y = j;
                }
            }
        }
        scanf("%s", op);
        status = STATUS_NO;
        for (int i = 0; op[i]; ++i)
        {
            switch (op[i])
            {
            case 'U':
                test(--x, y);
                break;
            case 'D':
                test(++x, y);
                break;
            case 'L':
                test(x, --y);
                break;
            case 'R':
                test(x, ++y);
                break;
            }
            if (status != STATUS_NO)
            {
                break;
            }
        }
        switch (status)
        {
        case STATUS_NO:
            puts("Oh no!");
            break;
        case STATUS_OOPS:
            puts("Oooooops!");
            break;
        case STATUS_SUCCESS:
            puts("Good job!");
            break;
        }
    }
    return 0;
}

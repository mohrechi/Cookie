#include <cstdio>
const int MAXN = 105;

int mat[MAXN][MAXN];
int temp[MAXN][MAXN];
char op[MAXN];

inline void copy(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            mat[x + i][y + j] = temp[i][j];
        }
    }
}

inline void rotateLeft(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = mat[x + j][y + n - i - 1];
        }
    }
}

inline void rotateRight(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = mat[x + n - j - 1][y + i];
        }
    }
}

inline void symmetryHor(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = mat[x + n - i - 1][y + j];
        }
    }
}

inline void symmetryVer(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = mat[x + i][y + n - j - 1];
        }
    }
}

inline void center(int x, int y, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            temp[i][j] = mat[x + n - i - 1][y + n - j - 1];
        }
    }
}

int main()
{
    int t, n, q, x, y, l;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        while (q--)
        {
            scanf("%s%d%d%d", op, &x, &y, &l);
            switch (op[0])
            {
            case 'R':
                switch (op[7])
                {
                case 'L':
                    rotateLeft(x, y, l);
                    break;
                case 'R':
                    rotateRight(x, y, l);
                    break;
                }
                break;
            case 'S':
                switch (op[9])
                {
                case 'H':
                    symmetryHor(x, y, l);
                    break;
                case 'V':
                    symmetryVer(x, y, l);
                    break;
                }
                break;
            case 'C':
                center(x, y, l);
                break;
            }
            copy(x, y, l);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1)
                {
                    putchar(' ');
                }
                printf("%d", mat[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}

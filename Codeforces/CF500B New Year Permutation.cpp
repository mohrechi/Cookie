#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;

int n, p[MAXN];
char A[MAXN][MAXN];

int color[MAXN];

void dfs(int u, int f)
{
    color[u] = color[f];
    for (int v = 0; v < n; ++v)
    {
        if (color[v] == -1 && A[u][v] == '1')
        {
            dfs(v, f);
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", A[i]);
    }
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            color[i] = i;
            dfs(i, i);
        }
    }
    int buffer[MAXN], num;
    for (int i = 0; i < n; ++i)
    {
        if (color[i] != -1)
        {
            num = 0;
            for (int j = i; j < n; ++j)
            {
                if (color[j] == i)
                {
                    buffer[num++] = p[j];
                }
            }
            sort(buffer, buffer + num);
            num = 0;
            for (int j = i; j < n; ++j)
            {
                if (color[j] == i)
                {
                    p[j] = buffer[num++];
                    color[j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
    return 0;
}

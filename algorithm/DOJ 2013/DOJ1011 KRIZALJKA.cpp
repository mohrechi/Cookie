#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[6][4];
bool visit[6];
bool tvisit[6];
long long ans;
char result[3][4];
int path[3];

void dfs(int depth)
{
    if (depth == 3)
    {
        for (int i = 0; i < 3; ++i)
        {
            strcpy(result[i], s[path[i]]);
        }
        char ts[4];
        memset(tvisit, false, sizeof(tvisit));
        int count = 0;
        for (int j = 0; j < 3; ++j)
        {
            for (int i = 0; i < 3; ++i)
            {
                ts[i] = result[i][j];
            }
            ts[3] = 0;
            for (int i = 0; i < 6; ++i)
            {
                if (!visit[i] && !tvisit[i])
                {
                    if (strcmp(ts, s[i]) == 0)
                    {
                        tvisit[i] = true;
                        ++count;
                        break;
                    }
                }
            }
        }
        if (count == 3)
        {
            long long temp = 0;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    temp = temp * 26 + result[i][j] - 'A';
                }
            }
            if (ans == -1)
            {
                ans = temp;
            }
            else
            {
                ans = min(ans, temp);
            }
        }
        return;
    }
    for (int i = 0; i < 6; ++i)
    {
        if (!visit[i])
        {
            visit[i] = true;
            path[depth] = i;
            dfs(depth + 1);
            visit[i] = false;
        }
    }
}

int main()
{
    while (~scanf("%s", s[0]))
    {
        for (int i = 1; i < 6; ++i)
        {
            scanf("%s", s[i]);
        }
        ans = -1;
        dfs(0);
        if (ans == -1)
        {
            printf("0\n");
        }
        else
        {
            for (int i = 2; i >= 0; --i)
            {
                for (int j = 2; j >= 0; --j)
                {
                    result[i][j] = (ans % 26) + 'A';
                    ans /= 26;
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                printf("%s\n", result[i]);
            }
        }
    }
    return 0;
}

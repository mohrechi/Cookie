#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, m;
char land[MAXN][MAXN];
int height[MAXN][MAXN];
int stack[MAXN], top;
int position[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", land[i] + 1);
            for (int j = 1; j <= m; ++j)
            {
                if (land[i][j] == '.')
                {
                    height[i][j] = height[i - 1][j] + 1;
                }
                else
                {
                    height[i][j] = 0;
                }
            }
        }
        map<int, int> ansMap;
        for (int i = 1; i <= n; ++i)
        {
            top = 0;
            for (int j = 1; j <= m; ++j)
            {
                if (height[i][j] == 0)
                {
                    top = 0;
                }
                else
                {
                    int left = j;
                    while (top > 0 && height[i][j] < stack[top - 1])
                    {
                        --top;
                        if (stack[top] >= height[i][j])
                        {
                            left = min(left, position[top]);
                        }
                    }
                    if (top == 0 || (top && height[i][j] != stack[top - 1]))
                    {
                        stack[top] = height[i][j];
                        position[top++] = left;
                    }
                }
                if (land[i][j] == '.')
                {
                    int temp = 0;
                    for (int k = 0; k < top; ++k)
                    {
                        temp = max(temp, (j - position[k] + 1 + stack[k]) << 1);
                    }
                    ++ansMap[temp];
                }
            }
        }
        for (map<int, int>::iterator it = ansMap.begin(); it != ansMap.end(); ++it)
        {
            printf("%d x %d\n", it->second, it->first);
        }
    }
    return 0;
}

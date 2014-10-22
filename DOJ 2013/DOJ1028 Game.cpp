#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int rotateNum[7] = {2, 1, 2, 2, 4, 4, 4};
const int width[7][4] =
{
    {1, 4, 0, 0},
    {2, 0, 0, 0},
    {3, 2, 0, 0},
    {3, 2, 0, 0},
    {3, 3, 2, 2},
    {3, 3, 2, 2},
    {3, 3, 2, 2}
};
const int bottom[7][4][4] =
{
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {1, 0, 1, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}},
    {{0, 0, 0, 0}, {0, 1, 1, 0}, {2, 0, 0, 0}, {0, 0, 0, 0}},
    {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 2, 0, 0}, {0, 0, 0, 0}}
};

int C, type;
int c[105];
int height[10];

int main()
{
    while (~scanf("%d%d", &C, &type))
    {
        --type;
        for (int i = 0; i < C; ++i)
        {
            scanf("%d", &c[i]);
        }
        int ans = 0;
        for (int i = 0; i < rotateNum[type]; ++i)
        {
            for (int j = 0; j + width[type][i] <= C; ++j)
            {
                bool flag = true;
                for (int k = 0; k < width[type][i]; ++k)
                {
                    height[k] = c[j + k] - bottom[type][i][k];
                    if (k)
                    {
                        if (height[k] != height[k - 1])
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                ans += flag;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

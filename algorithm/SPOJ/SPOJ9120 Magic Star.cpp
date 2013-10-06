#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char MAP[5][10] =
{
    {"....A...."},
    {".B.C.D.E."},
    {"..F...G.."},
    {".H.I.J.K."},
    {"....L...."}
};

int posX[12], posY[12];
char map[5][10];
bool visit[12];

void init()
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (MAP[i][j] >= 'A' && MAP[i][j] <= 'L')
            {
                posX[MAP[i][j] - 'A'] = i;
                posY[MAP[i][j] - 'A'] = j;
            }
        }
    }
}

inline bool validLineSub(char a, char b, char c, char d)
{
    if (a == 'x' || b == 'x' || c == 'x' || d == 'x')
    {
        return true;
    }
    return a + b + c + d - 'A' * 4 == 22;
}

inline bool validLine(char a, char b, char c, char d)
{
    return validLineSub(map[posX[a - 'A']][posY[a - 'A']],
                        map[posX[b - 'A']][posY[b - 'A']],
                        map[posX[c - 'A']][posY[c - 'A']],
                        map[posX[d - 'A']][posY[d - 'A']]);
}

inline bool valid()
{
    return validLine('A', 'C', 'F', 'H') &&
        validLine('A', 'D', 'G', 'K') &&
        validLine('B', 'C', 'D', 'E') &&
        validLine('B', 'F', 'I', 'L') &&
        validLine('H', 'I', 'J', 'K') &&
        validLine('E', 'G', 'J', 'L');
}

bool dfs(int depth)
{
    if (depth >= 12)
    {
        return true;
    }
    if (map[posX[depth]][posY[depth]] != 'x')
    {
        return dfs(depth + 1);
    }
    for (int i = 0; i < 12; ++i)
    {
        if (!visit[i])
        {
            map[posX[depth]][posY[depth]] = i + 'A';
            if (valid())
            {
                visit[i] = true;
                if (dfs(depth + 1))
                {
                    return true;
                }
                visit[i] = false;
            }
            map[posX[depth]][posY[depth]] = 'x';
        }
    }
    return false;
}

int main()
{
    init();
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < 5; ++i)
    {
        scanf("%s", map[i]);
        for (int j = 0; j < 9; ++j)
        {
            if (map[i][j] >= 'A' && map[i][j] <= 'L')
            {
                visit[map[i][j] - 'A'] = true;
            }
        }
    }
    dfs(0);
    for (int i = 0; i < 5; ++i)
    {
        printf("%s\n", map[i]);
    }
    return 0;
}

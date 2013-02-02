#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = 10005;

int n, m;
char map[MAXN][MAXM];

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(map, '#', sizeof(map));
        for(int i=1;i<=n;++i)
        {
            scanf("%s", map[i] + 1);
            map[i][m + 1] = '#';
        }
        int dir = 1;
        int ceil = 1;
        long long ans = 0;
        bool flag = true;
        for(int floor = 1;floor<n && flag;++floor)
        {
            int left = ceil, right = ceil;
            while(true)
            {
                if(map[floor + 1][ceil] == '.')
                {
                    ++ ans;
                    break;
                }
                if(map[floor][left - 1] == '#' && map[floor][right + 1] == '#')
                {
                    flag = false;
                    break;
                }
                if(dir == 0)
                {
                    ans += (ceil - left);
                    ceil = left;
                    for(;;--ceil)
                    {
                        if(map[floor + 1][ceil] == '.')
                        {
                            break;
                        }
                        else
                        {
                            ++ ans;
                            if(map[floor][ceil - 1] == '#')
                            {
                                dir = !dir;
                                break;
                            }
                            else if(map[floor][ceil - 1] == '+')
                            {
                                map[floor][ceil - 1] = '.';
                                dir = !dir;
                                break;
                            }
                        }
                    }
                    left = ceil;
                }
                else
                {
                    ans += (right - ceil);
                    ceil = right;
                    for(;;++ceil)
                    {
                        if(map[floor + 1][ceil] == '.')
                        {
                            break;
                        }
                        else
                        {
                            ++ ans;
                            if(map[floor][ceil + 1] == '#')
                            {
                                dir = !dir;
                                break;
                            }
                            else if(map[floor][ceil + 1] == '+')
                            {
                                map[floor][ceil + 1] = '.';
                                dir = !dir;
                                break;
                            }
                        }
                    }
                    right = ceil;
                }
            }
        }
        if(flag)
        {
            printf("%I64d\n", ans);
        }
        else
        {
            printf("Never\n");
        }
    }
    return 0;
}

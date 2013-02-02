#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int MAXM = 2005;

int father[MAXN], team[MAXN];
int n, m, x[MAXM], y[MAXM];
char op[MAXM];
int judgeNumber, judgePos;
int lineNumber;

void init()
{
    for(int i=0;i<n;++i)
    {
        father[i] = i;
        team[i] = 0;
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    int temp = father[x];
    father[x] = find(temp);
    team[x] = (team[temp] + team[x]) % 3;
    return father[x];
}

void combine(int x, int y, int o)
{
    int fx = find(x);
    int fy = find(y);
    team[fx] = (team[y] - team[x] + o + 3) % 3;
    father[fx] = fy;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<m;++i)
        {
            scanf("%d%c%d", &x[i], &op[i], &y[i]);
            switch(op[i])
            {
                case '=': op[i] = 0; break;
                case '>': op[i] = 1; break;
                case '<': op[i] = 2; break;
            }
        }
        judgeNumber = 0;
        lineNumber = 0;
        for(int i=0;i<n;++i)
        {
            init();
            bool flag = true;
            for(int j=0;j<m;++j)
            {
                if(x[j] == i || y[j] == i)
                {
                    continue;
                }
                int fx = find(x[j]);
                int fy = find(y[j]);
                if(fx == fy)
                {
                    if(team[x[j]] != (team[y[j]] + op[j]) % 3)
                    {
                        flag = false;
                        lineNumber = max(lineNumber, j + 1);
                        break;
                    }
                }
                else
                {
                    combine(x[j], y[j], op[j]);
                }
            }
            if(flag)
            {
                if(++ judgeNumber > 1)
                {
                    break;
                }
                judgePos = i;
            }
        }
        if(0 == judgeNumber)
        {
            printf("Impossible\n");
        }
        else if(1 == judgeNumber)
        {
            printf("Player %d can be determined to be the judge after %d lines\n", judgePos, lineNumber);
        }
        else
        {
            printf("Can not determine\n");
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 25;
int n, m, edge, sum;

int stick[MAXN];
bool used[MAXN];

bool dfs(int x, int depth, int length)
{
    if(depth == n)
    {
        return true;
    }
    if(length == 0)
    {
        x = 0;
    }
    for(int i=x;i<n;++i)
    {
        if(!used[i] && stick[i] + length <= edge)
        {
            used[i] = true;
            if(dfs(i + 1, depth + 1, stick[i] + length < edge ? stick[i] + length : 0))
            {
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    scanf("%d",&m);
    while(m--)
    {
        bool flag = true;
        sum = 0;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d", &stick[i]);
            sum += stick[i];
        }
        stick[n] = -1;
        if(sum % 4 == 0)
        {
            edge = sum / 4;
            memset(used, false, sizeof(used));
            flag = dfs(0, 0, 0);
        }
        else
        {
            flag = false;
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

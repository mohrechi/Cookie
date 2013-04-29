#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[4], b[4], c[4];
bool v[4];

bool judge()
{
    int ans = b[0];
    for(int i=0;i<3;++i)
    {
        switch(c[i])
        {
            case 0:
                ans += b[i + 1];
                break;
            case 1:
                ans -= b[i + 1];
                break;
            case 2:
                ans *= b[i + 1];
                break;
            case 3:
                if(ans % b[i + 1] == 0)
                {
                    ans /= b[i + 1];
                }
                else
                {
                    return false;
                }
                break;
        }
    }
    return ans == 24;
}

bool dfs2(int depth)
{
    if(depth == 3)
    {
        return judge();
    }
    for(int i=0;i<4;++i)
    {
        c[depth] = i;
        if(dfs2(depth + 1))
        {
            return true;
        }
    }
    return false;
}

bool dfs1(int depth)
{
    if(depth == 4)
    {
        return dfs2(0);
    }
    for(int i=0;i<4;++i)
    {
        if(!v[i])
        {
            v[i] = true;
            b[depth] = a[i];
            if(dfs1(depth + 1))
            {
                return true;
            }
            v[i] = false;
        }
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        for(int i=0;i<4;++i)
        {
            scanf("%d", &a[i]);
            v[i] = false;
        }
        if(dfs1(0))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>

int n;
char s[105][105];

bool possible(int x)
{
    for(int i=0;i<11;++i)
    {
        if(s[x][i] == '*')
        {
            continue;
        }
        if(s[x][i] != s[n][i])
        {
            return false;
        }
    }
    return true;
}

bool judge()
{
    for(int i=0;i<n;++i)
    {
        if(possible(i))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        for(int i=0;i<=n;++i)
        {
            scanf("%s", s[i]);
        }
        if(judge())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

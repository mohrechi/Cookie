#include <cstdio>
#include <cstring>
int n;
bool g[105][105];
char s[128];
char fit[25][4];
int num[25];

int getIndex(char ch)
{
    switch(ch)
    {
        case 'S': return 0;
        case 'M': return 1;
        case 'L': return 2;
        case 'X': return 3;
        case 'T': return 4;
    }
}

bool visit[105];
int match[105];

bool find(int x)
{
    for(int i=0;i<100;++i)
    {
        if(g[x][i] && !visit[i])
        {
            visit[i] = true;
            if(match[i] == -1 || find(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

bool hungray()
{
    memset(match, -1, sizeof(match));
    for(int i=0;i<n;++i)
    {
        memset(visit, false, sizeof(visit));
        if(!find(i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    while(scanf("%s", s), *s != 'E')
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%s", fit[i]);
        }
        for(int i=0;i<5;++i)
        {
            scanf("%d", &num[i]);
        }
        scanf("%s", s);
        memset(g, false, sizeof(g));
        for(int i=0;i<n;++i)
        {
            for(int j=getIndex(fit[i][0]);j<=getIndex(fit[i][1]);++j)
            {
                for(int k=0;k<num[j];++k)
                {
                    g[i][j*20 + k] = true;
                }
            }
        }
        if(hungray())
        {
            printf("T-shirts rock!\n");
        }
        else
        {
            printf("I'd rather not wear a shirt anyway...\n");
        }
    }
    return 0;
}

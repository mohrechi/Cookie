#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

char temp[50];
char name[MAXN][50];
int value[MAXN];
int n;

int getValue(const char *s)
{
    for(int i=0;i<n;++i)
    {
        if(strcmp(name[i], s) == 0)
        {
            return value[i];
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%s%d", name[i], &value[i]);
        }
        int a = 0, b = 0;
        for(int i=0;i<5;++i)
        {
            scanf("%s", temp);
            a += getValue(temp);
        }
        for(int i=0;i<5;++i)
        {
            scanf("%s", temp);
            b += getValue(temp);
        }
        if(a >= b)
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

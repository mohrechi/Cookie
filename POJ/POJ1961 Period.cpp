#include <cstdio>
#include <cstring>
static const int MAXN = 1000005;
int t, l;
char s[MAXN];
int next[MAXN];

int main(int argc, char *argv[])
{
    int i, j;
    while(scanf("%d",&l), l)
    {
        printf("Test case #%d\n", ++t);
        scanf("%s", s);
        i = 0, j = -1, next[0] = -1;
        while(i < l)
        {
            if(j==-1 || s[i] == s[j])
            {
                ++i, ++j, next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
        for(i=2;i<=l;++i)
        {
            j = i - next[i];
            if(i % j == 0 && i > j)
            {
                printf("%d %d\n", i, i/j);
            }
        }
        printf("\n");
    }
    return 0;
}

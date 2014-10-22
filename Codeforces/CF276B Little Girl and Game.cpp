#include <cstdio>
#include <cstring>
const int MAXN = 1005;

int count[30];
char s[MAXN];

int main()
{
    scanf("%s", s);
    for(int i=0;s[i];++i)
    {
        ++ count[s[i] - 'a'];
    }
    int num = 0;
    for(int i=0;i<26;++i)
    {
        if(count[i])
        {
            num += count[i] & 1;
        }
    }
    if(num == 0)
    {
        printf("First\n");
    }
    else
    {
        if(num & 1)
        {
            printf("First\n");
        }
        else
        {
            printf("Second\n");
        }
    }
    return 0;
}

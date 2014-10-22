#include <cstdio>
#include <cstring>

int main()
{
    char s[100];
    int ans[100];
    scanf("%s", s);
    int l = strlen(s);
    for(int i=0;i<l;++i)
    {
        ans[i] = s[i] - '0';
    }
    while(~scanf("%s", s))
    {
        for(int i=0;i<l;++i)
        {
            ans[i] += s[i] - '0';
        }
    }
    for(int i=0;i<l;++i)
    {
        printf("%d", ans[i]%10);
    }
    printf("\n");
    return 0;
}

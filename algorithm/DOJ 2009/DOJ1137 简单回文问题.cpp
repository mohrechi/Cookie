#include <cstdio>
#include <cstring>

char s[100];

int main()
{
    while(~scanf("%s", s))
    {
        int len = strlen(s);
        int i = 0, j = len - 1;
        for(;i<j;++i,--j)
        {
            if(s[i] != s[j])
            {
                break;
            }
        }
        if(i < j)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}

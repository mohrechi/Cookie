#include <cstdio>
#include <cstring>

int main()
{
    char s[128];
    int l;
    while(gets(s))
    {
        l = strlen(s);
        for(int i=l-1;i>=0;--i)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}

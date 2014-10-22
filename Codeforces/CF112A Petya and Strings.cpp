#include <cstdio>
#include <cstring>

char s1[105], s2[105];

int main()
{
    while(~scanf("%s%s", s1, s2))
    {
        strlwr(s1);
        strlwr(s2);
        printf("%d\n", strcmp(s1, s2));
    }
    return 0;
}

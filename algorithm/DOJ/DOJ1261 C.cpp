#include <cstdio>
#include <cstring>

char s[105];

int main()
{
    while(scanf("%s", s) != EOF)
    {
        int l = strlen(s);
        for(int i=0;i<l;++i)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        for(int i=0;i<l;++i)
        {
            if(s[i] == 'a' || s[i] == 'o' ||
               s[i] == 'y' || s[i] == 'e' ||
               s[i] == 'u' || s[i] == 'i')
               {
                   continue;
               }
               else
               {
                   printf(".%c", s[i]);
               }
        }
        printf("\n");
    }
    return 0;
}

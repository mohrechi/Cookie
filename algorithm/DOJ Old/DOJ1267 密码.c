#include <stdio.h>
#include <string.h>
int main()
{
    char pass_low[27], pass_up[27];
    char s[81], c;
    int len, i;
    gets(pass_low);
    pass_up[26] = '\0';
    for (i=strlen(pass_low); i>=0; i--)
        pass_up[i] = pass_low[i]-'a'+'A';
    gets(s);
    len = strlen(s);
    for (i=0; i<len; i++){
        c = s[i];
        if (c == ' ')
            printf(" ");
        else if (c>='a' && c<='z')
            printf("%c", pass_low[c-'a']);
        else if (c>='A' && c<='Z')
            printf("%c", pass_up[c-'A']);
    }
    return 0;
}

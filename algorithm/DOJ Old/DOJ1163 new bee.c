#include<stdio.h>
#include<string.h>

main ()
{
    char s1[105],s2[105],i,j=0;
    gets(s1);
    gets(s2);
    for (i=0;i<strlen(s1);i++)
    {
        if (s1[i]==s2[i])
        {
            j++;
        }
    }
    j=strlen(s1)-j;
    printf("%d",j);
    return 0;
}

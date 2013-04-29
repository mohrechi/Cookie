#include<stdio.h>

main ()
{
    char c1[105],c2[105],i,j=0;
    scanf("%s%s",c1,c2);
    for(i=0;c1[i]!='\0';i++)
    {
        if (c1[i]>='a'&&c1[i]<='z')
        {
            c1[i]-=32;
        }
        if (c2[i]>='a'&&c2[i]<='z')
        {
            c2[i]-=32;
        }
    }
    for(i=0;c1[i]!='\0';i++)
    {
        if (c1[i]!=c2[i])
        {
            j++;
        }
    }
    printf("%d\n",j);
    return 0;
}

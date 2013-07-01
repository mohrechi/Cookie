#include<stdio.h>
#include<string.h >

main()
{
    char s[110][40],c[40];
    int i=1,j,x,y,judge;
    while(scanf("%s",s[i])!=EOF)
    {
        strcpy(c,strlwr(s[i]));
        judge=0;
        while(!judge)
        {
            if(c[0]=='_'||c[0]=='-'||c[0]=='.')
            {
                judge=1;
                break;
            }
            if(judge==1)break;
            for(x=1;x<i;x++)
            {
                if(strcmp(c,strlwr(s[x]))==0)
                {
                    judge=1;
                    break;
                }
            }
            if(judge==1)break;
            for(x=0;c[x]!='\0';x++)
            {
                judge=1;
                if ((c[x]>='0'&&c[x]<='9')||(c[x]>='a'&&c[x]<='z')||c[x]=='_'||c[x]=='-'||c[x]=='.')
                {
                    judge=0;
                }
                else
                {
                    break;
                }
                if(c[x]=='a'&&c[x+1]=='d'&&c[x+2]=='m'&&c[x+3]=='i'&&c[x+4]=='n')
                {
                    judge=1;
                    break;
                }
            }
            break;
        }
        if (judge==0)
        {
            printf("right\n");
            i++;
        }
        else
        {
            printf("error\n");
        }
    }
    return 0;
}

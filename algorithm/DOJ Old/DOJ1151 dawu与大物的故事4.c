#include<stdio.h>
#include<string.h>

main ()
{
    char s1[510],s2[510];
    int i,j,k,in,m,n;
    while (scanf("%s%s",s1,s2)!=EOF)
    {
        in=0;
        m=strlen(s1);
        n=strlen(s2);
        for(i=0;i<m-n+1;i++)
        {
            if(s1[i]==s2[0])
            {
                in=1,k=i;
                for(j=1;j<n;j++)
                {
                    if(s1[++k]!=s2[j])
                    {
                        in=0;
                    }
                }
                if(in==1)
                {
                    break;
                }
            }
        }
        if (in==0)
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

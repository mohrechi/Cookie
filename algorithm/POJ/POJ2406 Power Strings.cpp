#include<stdio.h>
#include<string.h>

char s[1000005];
int main()
{
    while(scanf("%s",s),*s!='.')
    {
        int len=strlen(s),i,j,k;
        for(i=1;i<len;i++)
        {
            if(len%i==0)
            {
                for(j=i;j<len;)
                {
                    for(k=0;k<i;j++,k++)
                    {
                        if(s[j]!=s[k])
                        {
                            break;
                        }
                    }
                    if(k<i)
                    {
                        break;
                    }
                }
                if(j==len)
                {
                    break;
                }
            }
        }
        printf("%d\n",len/i);
    }
    return 0;
}

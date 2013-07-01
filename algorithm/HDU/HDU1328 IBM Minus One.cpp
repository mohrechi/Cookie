#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    char s[100];
    scanf("%d",&t);
    for(int i=1;i<=t;++i)
    {
        scanf("%s",s);
        for(int j=0;s[j];++j)
        {
            if(s[j]=='Z') s[j]='A';
            else ++s[j];
        }
        printf("String #%d\n%s\n\n",i,s);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char s1[27],s2[27];

void create(int pa, int pb, int ia, int ib)
{
    if(pa==pb)
    {
        printf("%c",s1[pa]);
        return;
    }
    if(pa>pb || ia>ib) return;
    int i;
    for(i=ia;i<=ib;i++)
    {
        if(s1[pa]==s2[i]) break;
    }
    int l=i-ia;
    create(pa+1,pa+l,ia,i-1);
    create(pa+l+1,pb,i+1,ib);
    printf("%c",s1[pa]);
}

int main()
{
    int len;
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        len=strlen(s1);
        create(0,len-1,0,len-1);
        printf("\n");
    }
    return 0;
}

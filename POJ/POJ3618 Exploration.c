#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct c
{
    int a;
    int b;
}s[500005];

int cmp(const void* a, const void* b)
{
    return (*(struct c*)a).a-(*(struct c*)b).a;
}

int main(void)
{
    int n,t,i,temp;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i].b);
        s[i].a=abs(s[i].b);
    }
    qsort(s+1,n,sizeof(*s),cmp);
    s[0].a=0,s[0].b=0,temp=s[0].a;
    for(i=1;i<=n;temp=s[i++].b)
    {
        if(t<abs(s[i].b-temp))break;
        t-=abs(s[i].b-temp);
    }
    printf("%d\n",i-1);
    return 0;
}

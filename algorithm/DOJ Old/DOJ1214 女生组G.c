#include<stdio.h>

struct t
{
    int h;
    int m;
    int s;
};

main()
{
    struct t t[4],b;
    int n,a[4],i;
    scanf("%d",&n);
    while(n--)
    {
        for(i=0;i<4;i++)
        {
            scanf("%d:%d:%d",&t[i].h,&t[i].m,&t[i].s);
            a[i]=t[i].h*3600+t[i].m*60+t[i].s;
        }
        if(a[2]>=a[1]||a[0]>=a[3])
        {
            printf("Impossible\n");
            continue;
        }
        if(a[2]<=a[0]&&a[3]>=a[1])
        {
            i=a[1]-a[0];
            goto loop;
        }
        if(a[0]<=a[2]&&a[1]>=a[3])
        {
            i=a[3]-a[2];
            goto loop;
        }
        if(a[0]>=a[2]&&a[0]<=a[3])
        {
            i=a[3]-a[0];
        }
        if(a[2]<=a[1]&&a[2]>=a[0])
        {
            i=a[1]-a[2];
        }
        loop:
        b.h=i/3600,i-=b.h*3600;
        b.m=i/60,i-=b.m*60;
        b.s=i;
        if(b.h<10)printf("0"),printf("%d",b.h);else printf("%d",b.h);
        printf(":");
        if(b.m<10)printf("0"),printf("%d",b.m);else printf("%d",b.m);
        printf(":");
        if(b.s<10)printf("0"),printf("%d",b.s);else printf("%d",b.s);
        printf("\n");
    }
    return 0;
}

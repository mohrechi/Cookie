#include<stdio.h>
#include<stdlib.h>

struct node
{
     int a;
     int b;
} l[10005];

int cmp(const void *c,const void *b)
{
     struct node *cc=(struct node *)c;
     struct node *bb=(struct node *)b;
     return(((cc->b)>(bb->b))?1:-1);
}

main()
{
    int n,s,i,j,k,judge,min,t;
    while(1)
    {
        scanf("%d%d",&n,&s);
        if(n==0)
        {
            break;
        }
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i].a,&l[i].b);
        }
        qsort(l+1,n,sizeof(l[0]),cmp);
        for(i=1;i<=n;i++)
        {
            if(s>=l[i].b)
            {
                s+=l[i].a;
            }
            else
            {
                break;
            }
        }
        if (i==n+1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

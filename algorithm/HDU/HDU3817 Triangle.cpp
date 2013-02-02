#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a>c) a^=c,c^=a,a^=c;
        if(b>c) b^=c,c^=b,b^=c;
        a*=a, b*=b, c*=c;
        printf("Case %d: ",i);
        if(a+b>c) printf("Acute triangle\n");
        else if(a+b<c) printf("Obtuse triangle\n");
        else printf("Right triangle\n");
    }
    return 0;
}

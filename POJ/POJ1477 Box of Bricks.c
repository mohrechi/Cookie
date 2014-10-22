#include<stdio.h>
#include<math.h>

int main(void)
{
    int n,h[50],s,t,i,j=1;
    for(;;)
    {
        scanf("%d",&n);
        if(!n) break;
        for(i=0,t=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            t+=h[i];
        }
        t=t/n;
        for(i=0,s=0;i<n;i++) s+=abs(h[i]-t);
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j++,s/2);
    }
}

#include<stdio.h>

int main()
{
    int one[4],n[4],h[4][65],a,b,c,i,N,cas,t,flag;
    scanf("%d",&cas);
    while(cas--)
    {
        a=1;b=2;c=3;
        one[a]=one[b]=one[c]=1;
        scanf("%d",&N);
        scanf("%d",&n[a]);
        for(i=one[a];i<=n[a];i++) scanf("%d",&h[a][i]);
        scanf("%d",&n[b]);
        for(i=one[b];i<=n[b];i++) scanf("%d",&h[b][i]);
        scanf("%d",&n[c]);
        for(i=one[c];i<=n[c];i++) scanf("%d",&h[c][i]);
        flag=1;
        while(1)
        {
            if(n[c]==N||n[a]==N)
            {
                flag=1;break;
            }
            if(n[b]>0&&h[b][one[b]]==N)
            {
                flag=0;break;
            }
            if(n[a]>0&&h[a][one[a]]==N)
            {
                N--;
                n[a]--;
                one[a]++;
                t=b;b=c;c=t;
                continue;
            }
            if(h[c][one[c]]==N&&n[c]>0)
            {
                N--;
                n[c]--;
                one[c]++;
                t=b;b=a;a=t;
                continue;
            }
        }
        if(flag) printf("true\n");
        else printf("false\n");
    }
    return 0;
}

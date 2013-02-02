#include<stdio.h>

int main(int argc, char* argv[])
{
    int n,m,c,a[30],b[30],t,s,i,f,d=0,max;
    while(scanf("%d%d%d",&n,&m,&c),m||n||c)
    {
        printf("Sequence %d\n",++d);
        for(i=0,s=0,max=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=0;
        }
        for(i=0,f=0;i<m;i++)
        {
            scanf("%d",&t);
            t--;
            if(b[t])
            {
                s-=a[t];
                b[t]=0;
            }
            else
            {
                s+=a[t];
                if(s>c)f=1;
                if(s>max)max=s;
                b[t]=1;
            }
        }
        if(f) printf("Fuse was blown.\n\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max);
    }
	return 0;
}

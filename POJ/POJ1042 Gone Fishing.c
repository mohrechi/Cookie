#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,t,a[30],b[30],c[30],d[30],e[30],f[30],i,j,k,s,m,max,tp;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&t);
        t*=60;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            c[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=1,d[0]=0;i<n;i++)
        {
            scanf("%d",&d[i]);
            d[i]+=d[i-1];
        }
        for(i=1,max=-1;i<=n;i++)
        {
            tp=t-d[i-1]*5;
            for(j=1;j<=n;j++)
            {
                c[j]=0;
                f[j]=a[j];
            }
            for(s=0;tp>0;tp-=5)
            {
                for(j=1,k=1,m=0;j<=i;j++)
                {
                    if(f[j]>m)
                    {
                        m=f[j];
                        k=j;
                    }
                }
                if(f[k]<0)f[k]=0,c[k]-=5,c[1]+=5;
                s+=f[k],f[k]-=b[k],c[k]+=5;
            }
            if(s>max)
            {
                max=s;
                for(j=1;j<=n;j++)
                {
                    e[j]=c[j];
                }
            }
        }
        for(i=1;i<n;i++)
        {
            printf("%d, ",e[i]);
        }
        printf("%d \nNumber of fish expected: %d \n\n",e[i],max);
    }
	return 0;
}

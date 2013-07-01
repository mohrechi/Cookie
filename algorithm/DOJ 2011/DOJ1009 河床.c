#include<stdio.h>
#include<math.h>

main ()
{
    int n,k,m=0,d[30005],i,s,min,max;
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }
    for (i=1;i<n;i++)
    {
        if (fabs(d[i]-d[i+1])<=k)
        {
            min=d[i]>d[i+1]?d[i+1]:d[i];
            max=d[i]>d[i+1]?d[i]:d[i+1];
            s=1;
            while ((max-min)<=k)
            {
                if (i+s==n+1)
                {
                    break;
                }
                s++;
                min=min<d[i+s]?min:d[i+s];
                max=max>d[i+s]?max:d[i+s];
            }
            if (s>m)
            {
                m=s;
            }
        }
    }
    if(n==1||m==0)
    {
        m=1;
    }
    printf("%d\n",m);
    return 0;
}

#include<stdio.h>

main()
{
    int n,i,j,max,m;
    int a[501],number,num;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&a[i]);
        }
        number=a[1];
        max=1;
        for(i=2;i<=n;i++)
        {
            if(a[i]==number)
            {
                max++;
                a[i]=0;
            }
        }
        for(j=2;j<=n;j++)
        {
            while(a[j]==0)
            {
                j++;
            }
            num=a[j];
            m=1;
            for (i=j+1;i<=n;i++)
            {
                if(a[i]==num)
                {
                    m++;
                    a[i]=0;
                }
            }
            if (m>max)
            {
                max=m;
                number=num;
            }
            if (m==max)
            {
                if(num<number)
                {
                    number=num;
                }
            }
        }
        printf("%d\n",number);
    }
    return 0;
}

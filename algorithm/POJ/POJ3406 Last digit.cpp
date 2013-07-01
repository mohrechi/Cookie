#include<stdio.h>

int main()
{
    int n,m,n2,n5,m2,m5;
    while(scanf("%d%d",&n,&m)==2)
    {
       int tn,tm,ans=1;
       n2=n5=m2=m5=0;
       if(m>n/2)
       {
           m=n-m;
       }
       for(int i=0;i<m;i++)
       {
            tn=ans*n--;
            tm=m-i;
            while((tn&1)==0)
            {
                n2++;
                tn/=2;
            }
            while(tn%5==0)
            {
                n5++;
                tn/=5;
            }
            while(tm%5==0)
            {
                m5++;
                tm/=5;
            }
            while((tm&1)==0)
            {
                m2++;
                tm/=2;
            }
            for(ans=1;;ans++)
            {
                if((ans*tm)%10==tn%10)
                {
                    break;
                }
            }
        }
        n2=n2-m2;
        n5=n5-m5;
        if(n2>=n5)
        {
            n2=n2-n5; n5=0;
        }
        if(n5>=n2)
        {
            n5=n5-n2; n2=0;
        }
        while(n2--)
        {
            ans=(ans*2)%10;
        }
        while(n5--)
        {
            ans=(ans*5)%10;
        }
        printf("%d\n",ans);
    }
    return 0;
}

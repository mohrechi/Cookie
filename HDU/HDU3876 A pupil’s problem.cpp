#include <stdio.h>
#include <math.h>
#include <string.h>

int dblcmp(double r)
{
    if(fabs(r)<1e-6) return 0;
    return r>0?1:-1;
}

char s1[100],s2[100];

int main()
{
    int t;
    double a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        double d = b*b;
        double e = 4*a*c;
        double r=d-e;
        if(dblcmp(r)==-1)
        {
            printf("NO\n");
        }
        else if(dblcmp(r)==0)
        {
            double ans = -b*0.5*a;
            sprintf(s1,"%.2lf",ans);
            if(!strcmp(s1,"-0.00"))
            {
                for(int i=0;s1[i];i++)
                {
                    s1[i]=s1[i+1];
                }
            }
            printf("%s\n",s1);
        }
        else
        {
            double t=sqrt(r);
            double ans1 = (-b-t)*0.5/a;
            double ans2 = (-b+t)*0.5/a;
            double temp;
            if(ans2<ans1)
            {
                temp=ans1;
                ans1=ans2;
                ans2=temp;
            }
            sprintf(s1,"%.2lf",ans1);
            sprintf(s2,"%.2lf",ans2);
            if(!strcmp(s1,"-0.00"))
            {
                for(int i=0;s1[i];i++)
                {
                    s1[i]=s1[i+1];
                }
            }
            if(!strcmp(s2,"-0.00"))
            {
                for(int i=0;s2[i];i++)
                {
                    s2[i]=s2[i+1];
                }
            }
            printf("%s %s\n",s1,s2);
        }
    }
    return 0;
}

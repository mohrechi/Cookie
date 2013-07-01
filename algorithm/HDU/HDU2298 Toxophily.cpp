#include<stdio.h>
#include<math.h>

#define g 9.8
#define eps 1e-8
#define pi acos(-1.0)

double x,y,V ;

double calcu(double s)
{
    double t=x/(V*cos(s));
    return V*sin(s)*t-0.5*g*t*t ;
}

void er_fen(double lc,double rc)
{
    double res,mid ;
    while(rc-lc>eps)
    {
        mid=(lc+rc)/2 ;
        res=calcu(mid);
        if(res>y)rc=mid ;
        else lc=mid ;
    }
    printf("%.6lf\n",mid);
}

void san_fen()
{
    double lc,rc,mid1,mid2,res1,res2,ty ;
    lc=0 ;
    rc=pi/2 ;
    do
    {
        mid1=(lc+rc)/2 ;
        mid2=(mid1+rc)/2 ;
        res1=calcu(mid1);
        res2=calcu(mid2);
        if(res1<res2)lc=mid1 ;
        else rc=mid2 ;
    }
    while(rc-lc>eps);
    if(res1<res2)res1=res2 ;
    if(res1<y)
    {
        printf("-1\n");
        return ;
    }
    else
    {
        er_fen(0,rc);
    }
}

int main()
{
    int t ;
    double s,ty ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&V);
        san_fen();
    }
    return 0 ;
}

#include<stdio.h>

__int64 ext_gcd(__int64  a,__int64  b,__int64  &x,__int64 &y)
{
    __int64 d;
    if(b==0) { x=1; y=0; return a; }
    d=ext_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}

__int64 ax_b_mod_n(__int64  a,__int64  b,__int64  n)
{
    __int64 d,x,y,t;
    d=ext_gcd(a,b,x,y);
    if(n%d==0)
    {
        x=x*n/d;
        t=b/d;
        if(t<0) t=-t;
        x=(x%t + t) %t;
        return x;
    }
    return -1;
}

int main()
{
    __int64 x,y,m,n,l,t;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
    t=ax_b_mod_n(m-n,l,y-x);
    if(t==-1)
    {
        printf("Impossible\n");
    }
    else
    {
        printf("%I64d\n",t);
    }
    return 0;
}

#include<stdio.h>

int main(int argc, char* argv[])
{
	__int64 a,b,c,m,n,i,j,p[10000];
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&n);
	if(a>b)i=a,a=b,b=i;
	if(c<a)i=c,c=b,b=a,a=i;
	else if(c<b)i=b,b=c,c=i;
	p[0]=1,p[1]=a;
	for(j=2;j<=n;j++)
	{
	    for(i=j-1;p[i]*a>p[j-1]&&i>=0;i--);
	    m=p[i+1]*a;
	    for(i=j-1;p[i]*b>p[j-1]&&i>=0;i--);
	    if(p[i+1]*b<m) m=p[i+1]*b;
	    for(i=j-1;p[i]*c>p[j-1]&&i>=0;i--);
	    if(p[i+1]*c<m) m=p[i+1]*c;
	    p[j]=m;
	}
	printf("%I64d\n",p[n]);
	return 0;
}

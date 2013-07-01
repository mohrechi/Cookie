#include<stdio.h>

int main(int argc, char* argv[])
{
	int     n;
	int     a[500];
	int     i;
	int     j;
	int     t;
	int     s;
	scanf("%d",&n);
	for(i=3;;i++)
        if(((2+i)*(i-1))/2>n) break;
    i--, t=(n-((2+i)*(i-1))/2)/(i-1), s=0;
    for(j=2;j<=i;j++) a[j]=j+t,s+=a[j];
    t=n-s;
    while(t--) a[--j]++;
    for(j=2;j<i;j++) printf("%d ",a[j]);
    printf("%d\n",a[j]);
	return 0;
}

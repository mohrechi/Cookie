#include<stdio.h>

int main(void)
{
	int a[1200]={1,0},b[500],i,j,m,n;
	int min,max;
	for(i=2;i<600;i++)
	    for(j=2;i*j<1200;j++)
            a[i*j]=1;
    for(i=1,j=0;i<1200;i++)
        if(!a[i])b[j++]=i;
    for(i=j;i<500;i++)
        b[i]=9999;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        printf("%d %d:",m,n);
        for(i=1;i<500;i++)
            if(b[i]>m) break;
        min=(i+1)/2-n>0?(i+1)/2-n:0;
        max=i%2?n*2-1:n*2;
        for(j=min,i=0;i<max;i++,j++)
            if(b[j]<=m)printf(" %d",b[j]);
            else break;
        printf("\n\n");
    }
	return 0;
}

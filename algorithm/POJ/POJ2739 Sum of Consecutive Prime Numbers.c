#include<stdio.h>
short a[10005]={1,1,0};
short b[4000];
int main(int argc, char* argv[])
{
	int i,j,k,n,s,c;
	for(i=2;i<10005;i++)
        for(j=2;i*j<10005;j++)
            a[i*j]=1;
    for(i=0,j=0;i<10005;i++)
        if(!a[i])b[j++]=i;
    for(;;)
    {
        scanf("%d",&n);
        if(0==n) break;
        for(i=0,s=0,c=0;i<=j;i++,s=0)
        {
            for(k=i;s<n;k++) s+=b[k];
            if(s==n)c++;
        }
        printf("%d\n",c);
    }
	return 0;
}

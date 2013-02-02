#include<stdio.h>

int a[1400000]={0,0,1};
int b[100000]={2};
int main(int argc, char* argv[])
{
	int i,j,k,n;
	for(i=3;i<1400000;i+=2) a[i]=1;
	for(i=3;i<700000;i+=2)
	{
	    for(j=3;;j+=2)
	    {
            k=i*j;
            if(k>1400000) break;
            a[k]=0;
	    }
	}
	for(i=3,j=1;j<=100000;i+=2)
	{
	    if(a[i])b[j++]=i;
	}
	while(scanf("%d",&n),n)
	{
	    for(i=0;;i++) if(b[i]>=n) break;
	    if(b[i]==n) printf("0\n");
	    else printf("%d\n",b[i]-b[i-1]);
	}
	return 0;
}

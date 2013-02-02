#include<stdio.h>

int s[1000000]={0,0,1};
int main(int argc, char* argv[])
{
	int n,a,b,c,i,j,t;
	for(i=3;i<1000000;i+=2) s[i]=1;
	for(i=3;i<500000;i+=2)
	{
	    for(j=3;;j++)
	    {
	        t=i*j;
	        if(t>1000000) break;
	        s[t]=0;
	    }
	}
	while(scanf("%d%d%d",&a,&b,&n),a||b|n)
	{
	    c=0;
	    while(c<n)
	    {
	        if(s[a])c++;
	        a+=b;
	    }
	    printf("%d\n",a-b);
	}
	return 0;
}

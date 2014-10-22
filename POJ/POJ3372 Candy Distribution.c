#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,a[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912},n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag=0;
		for(i=0;i<30;i++)if(n==a[i])flag=1;
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

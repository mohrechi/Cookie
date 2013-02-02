#include <cstdio>
const int s[10]={1,1,2,6,24,120,720,5040,40320,362880};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			break;
		else if(n==0)
		{
			printf("NO\n");
		}
		else
		{
			for(int i=9;i>=0;i--)
			{
				if(n>=s[i])
					n=n-s[i];
			}
			if(n==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}

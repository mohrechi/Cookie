#include<stdio.h>

int main()
{
	int n,i,j,k,l,a[101];
	for(i=1;i<=100;i++)a[i]=i*i*i;
	scanf("%d",&n);
	for(i=6;i<=n;i++)
	{
		for(j=2;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if((a[j]+a[k])>a[i])break;
				for(l=k+1;l<=n;l++)
				{
					if((a[j]+a[k]+a[l])>a[i])break;
					if(a[i]==a[j]+a[k]+a[l])
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
					}
				}
			}
		}
	}
}

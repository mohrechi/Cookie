#include<stdio.h>

char a[25][25]={0},b[100]={0};
int max=0;

int f(int i, int j, int n)
{
    if(a[i][j])
    {
        if(!b[a[i][j]])
        {
            n++,b[a[i][j]]=1;
            if(n>max) max=n;
            f(i-1,j,n);
            f(i+1,j,n);
            f(i,j-1,n);
            f(i,j+1,n);
            b[a[i][j]]=0;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
	int m,n,i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	{
	    for(j=1;j<=n;j++)
	    {
	        scanf("%c",&a[i][j]);
	        if(a[i][j]<'A'||a[i][j]>'Z')
	        {
	            j--;
	        }
	    }
	}
	f(1,1,0);
	printf("%d\n",max);
	return 0;
}

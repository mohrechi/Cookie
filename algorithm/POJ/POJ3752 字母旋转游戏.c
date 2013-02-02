#include<stdio.h>

char a[1000][1000]={0};
int main(int argc, char* argv[])
{
	int m,n,s,i,j,t;
	scanf("%d%d",&m,&n);
	m++,n++;
	for(i=1;i<m;i++)a[i][n]=1,a[i][0]=1;
	for(j=1;j<n;j++)a[m][j]=1,a[0][j]=1;
	t=(m-1)*(n-1);
	for(i=1,j=0,s=0;;)
	{
	    for(++j;;)
	    {
	        if(a[i][j])break;
	        a[i][j]=s%26+65;
	        s++,j++;
	        if(a[i][j])
	        {
	            j--;
	            break;
	        }
	    }
	    for(++i;;)
	    {
	        if(a[i][j])break;
	        a[i][j]=s%26+65;
	        s++,i++;
	        if(a[i][j])
	        {
	            i--;
	            break;
	        }
	    }
	    for(--j;;)
	    {
	        if(a[i][j])break;
	        a[i][j]=s%26+65;
	        s++,j--;
	        if(a[i][j])
	        {
	            j++;
	            break;
	        }
	    }
	    for(--i;;)
	    {
	        if(a[i][j])break;
	        a[i][j]=s%26+65;
	        s++,i--;
	        if(a[i][j])
	        {
	            i++;
	            break;
	        }
	    }
	    if(s==t) break;
	}
	for(i=1;i<m;i++)
	{
	    for(j=1;j<n;j++)
	    {
	        printf("   %c",a[i][j]);
	    }
	    printf("\n");
	}
	return 0;
}

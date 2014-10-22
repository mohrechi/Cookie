#include<stdio.h>

int a[25][25];

int f(int x,int y)
{
    if(a[x][y])
    {
        a[x][y]=0;
        return f(x-1,y)+f(x+1,y)+f(x,y-1)+f(x,y+1)+1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int m,n,x,y,i,j;
    char c;
	for(;;)
	{
	    scanf("%d%d",&m,&n);
	    if(!m&&!n) break;
	    for(i=0;i<25;i++)
	    {
	        for(j=0;j<25;j++)
	        {
	            a[i][j]=0;
	        }
	    }
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=m;j++)
	        {
	            scanf("%c",&c);
	            if(c=='.') a[i][j]=1;
	            else if(c=='#');
	            else if(c=='@')
	            {
	                a[i][j]=1;
	                x=i,y=j;
	            }
	            else j--;
	        }
	    }
	    printf("%d\n",f(x,y));
	}
	return 0;
}

#include<stdio.h>

char a[1100][100]={0};

int f(int i, int j)
{
    if(a[i][j])
    {
        a[i][j]=0;
        return f(i-1,j)+f(i+1,j)+f(i,j-1)+f(i,j+1)+1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    int w,h,t,i,j,m,n;
    char c;
    scanf("%d%d",&w,&h);
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            scanf("%c",&c);
            if(c=='.') a[i][j]=0;
            else if(c=='*') a[i][j]=1;
            else j--;
        }
    }
    for(i=1,m=0;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            n=f(i,j);
            if(n>m)m=n;
        }
    }
    printf("%d\n",m);
	return 0;
}

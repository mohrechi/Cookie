#include<stdio.h>

int a[104][104];

int f(int i, int j)
{
    int c,b;
    if(a[i][j])
    {
        a[i][j]=0;
        for(c=-1;c<2;c++)
        {
            for(b=-1;b<2;b++)
            {
                f(i+c,j+b);
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char* argv[])
{
	int i,j,m,n,s;
	char c;
	for(i=0;i<104;i++)
    {
        for(j=0;j<104;j++)
        {
            a[i][j]=0;
        }
    }
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;)
        {
            scanf("%c",&c);
            if(c=='W') a[i][j]=1,j++;
            if(c=='.') j++;
        }
    }
    for(i=1,s=0;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            s+=f(i,j);
        }
    }
    printf("%d\n",s);
	return 0;
}

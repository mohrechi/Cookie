#include<stdio.h>

int num[110][110];

int f(int i, int j)
{
    int a,b;
    if(num[i][j])
    {
        num[i][j]=0;
        for(a=-1;a<2;a++)
            for(b=-1;b<2;b++)
                if(num[i+a][j+b])
                    f(i+a,j+b);
        return 1;
    }
    return 0;
}

int main(void)
{
	int i,j,m,n,s;
	char c;
	for(;;)
	{
	   scanf("%d%d",&m,&n);
	   if(!m&&!n) break;
	   for(i=0;i<110;i++)
            for(j=0;j<110;j++)
                num[i][j]=0;
	   for(i=1;i<=m;i++)
	   {
	       for(j=1;j<=n;j++)
	       {
	           scanf("%c",&c);
	           if(c=='*')num[i][j]=0;
	           else if(c=='@') num[i][j]=1;
	           else j--;
	       }
	   }
	   for(i=1,s=0;i<=m;i++)
	       for(j=1;j<=n;j++)
	           if(f(i,j)) s++;
	   printf("%d\n",s);
	}
	return 0;
}

#include<stdio.h>

int main(void)
{
	char a[101][101]={0},s[10];
	int i,j,t,x,y,c,l;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%s%d%d%d",s,&x,&y,&l);
	    if(*s=='B')
	        for(i=x;i<x+l;i++)
                for(j=y;j<y+l;j++)
                    a[i][j]=1;
        if(*s=='W')
	        for(i=x;i<x+l;i++)
                for(j=y;j<y+l;j++)
                    a[i][j]=0;
        if(*s=='T')
        {
	        for(i=x,c=0;i<x+l;i++)
                for(j=y;j<y+l;j++)
                    if(a[i][j]) c++;
            printf("%d\n",c);
        }
	}
	return 0;
}

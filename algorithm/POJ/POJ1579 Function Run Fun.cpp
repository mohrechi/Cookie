#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	int a,b,c,res[21][21][21];
	for(int i=0;i<21;i++)
	{
	    for(int j=0;j<21;j++)
	    {
	        res[0][i][j]=res[i][0][j]=res[i][j][0]=1;
	    }
	}
	for(int i=1;i<21;i++)
	{
	    for(int j=1;j<21;j++)
	    {
	        for(int k=1;k<21;k++)
	        {
	            if(i<j and j<k)
	            {
	                res[i][j][k]=res[i][j][k-1]+res[i][j-1][k-1]-res[i][j-1][k];
	            }
	            else
	            {
	                res[i][j][k]=res[i-1][j][k]+res[i-1][j-1][k]+res[i-1][j][k-1]-res[i-1][j-1][k-1];
	            }
	        }
	    }
	}
	while(scanf("%d%d%d",&a,&b,&c),a+1 or b+1 or c+1)
	{
	    printf("w(%d, %d, %d) = ",a,b,c);
	    if(a<0 or b<0 or c<0)
	    {
	        printf("1\n");
	    }
	    else if(a>20 or b>20 or c>20)
	    {
	        printf("%d\n",res[20][20][20]);
	    }
	    else
	    {
	        printf("%d\n",res[a][b][c]);
	    }
	}
	return 0;
}

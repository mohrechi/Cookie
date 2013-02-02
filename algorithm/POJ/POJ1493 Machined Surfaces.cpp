#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	char str[15][30];
	int n;
	while(scanf("%d",&n),n)
	{
	    int max=0,min=0;
	    int sum[15]={0};
	    getchar();
	    for(int i=0;i<n;i++)
	    {
	        gets(str[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<25;j++)
	        {
	            if(str[i][j]=='X')
	            {
	                sum[i]++;
	            }
	        }
	        if(sum[i]>max)
	        {
	            max=sum[i];
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        min+=max-sum[i];
	    }
	    cout<<min<<endl;
	}
	return 0;
}

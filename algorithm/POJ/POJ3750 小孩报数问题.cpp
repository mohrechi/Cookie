#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	int n,w,s,visited[100];
	char name[100][20];
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
	    gets(name[i]);
	    visited[i]=0;
	}
	scanf("%d,%d",&w,&s);
	for(int j=w-1,out=0;out<n;out++)
	{
	    for(int i=0;i<s;)
	    {
            if(j==n)
            {
                j=1;
            }
            else
            {
                j++;
            }
            if(not visited[j])
            {
                i++;
            }
	    }
        puts(name[j]);
        visited[j]=1;
	}
	return 0;
}

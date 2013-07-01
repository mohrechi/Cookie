#include<iostream>
using namespace std;
#include<stdio.h>

unsigned int a[35000];

int main(int argc, char* argv[])
{
	unsigned int sum=1, len=1;
	for(int i=1; i<35000; i++)
	{
	    a[i] = sum;
	    if(i==9 or i==99 or i==999 or i==9999)
	    {
	        len ++;
	    }
	    sum += len;
	}
	int cas;
	cin>>cas;
	while(cas--)
	{
	    int num;
	    cin>>num;
	    for(int i=1; i<35000; i++)
	    {
	        if(num>a[i])
	        {
	            num -= a[i];
	        }
	        else
	        {
	            break;
	        }
	    }
	    len = 1;
	    int i;
	    for(i=1; i<35000; i++)
	    {
	        if(num<=len)
	        {
	            break;
	        }
	        else
	        {
	            num -= len;
	            if(i==9 or i==99 or i==999 or i==9999)
                {
                    len ++;
                }
	        }
	    }
	    num = len - num;
	    while(num--)
	    {
	        i/=10;
	    }
	    cout<<i%10<<endl;
	}
	return 0;
}

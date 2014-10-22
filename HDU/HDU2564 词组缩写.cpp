#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	char s[1000];
	int t;
	bool flag;
	cin>>t;
    getchar();
	while(t--)
	{
	    gets(s);
	    flag=true;
	    for(int i=0;s[i];i++)
	    {
	        if(s[i]>='a' && s[i]<='z')
	        {
	            if(flag)
	            {
	                putchar(s[i]+'A'-'a');
	                flag = false;
	            }
	        }
	        else if(s[i]>='A' && s[i]<='Z')
	        {
	            if(flag)
	            {
	                putchar(s[i]);
	                flag=false;
	            }
	        }
	        else if(s[i]==' ')
	        {
	            flag = true;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}

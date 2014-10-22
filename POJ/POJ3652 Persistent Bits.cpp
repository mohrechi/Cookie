#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

bool visit[65536];

int main(int argc, char *argv[])
{
	char str[17] = {0};
	int a,b,c,s;
	while(scanf("%d",&a),a)
	{
	    scanf("%d%d%d",&b,&c,&s);
	    for(int i=0;i<16;i++)
	    {
	        str[15-i] = '0' + ((s&(1<<i))>0);
	    }
	    memset(visit, false,sizeof(visit));
	    visit[s] = true;
	    while(true)
	    {
            s = (a * s + b) % c;
            if(visit[s])
            {
                break;
            }
            else
            {
                visit[s] = true;
            }
	        for(int i=0;i<16;i++)
	        {
	            if(((s&(1<<i))>0)+'0'!=str[15-i])
	            {
	                str[15-i] = '?';
	            }
	        }
	    }
	    printf("%s\n",str);
	}
	return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

int var[5];
char s[105];
bool flag;
int pos;

bool tautology()
{
    switch(s[pos++])
    {
        case 'p': return var[0];
        case 'q': return var[1];
        case 'r': return var[2];
        case 's': return var[3];
        case 't': return var[4];
        case 'K': return tautology() & tautology();
        case 'A': return tautology() | tautology();
        case 'N': return !tautology();
        case 'C': return !tautology() | tautology();
        case 'E': return tautology() == tautology();
    }
    return false;
}

void dfs(int index)
{
    if(index == 5)
    {
        pos = 0;
        flag = tautology();
        return;
    }
    for(var[index]=0;var[index]<2 && flag;var[index]++)
    {
        dfs(index+1);
    }
}

int main(int argc, char *argv[])
{
	while(scanf("%s",s),*s!='0')
	{
	    flag = true;
	    dfs(0);
	    if(flag)
	    {
	        printf("tautology\n");
	    }
	    else
	    {
	        printf("not\n");
	    }
	}
	return 0;
}

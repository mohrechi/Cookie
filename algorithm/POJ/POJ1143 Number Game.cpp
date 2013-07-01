#include <iostream>
#include <stdio.h>
using namespace std;

char record[1<<21];

bool dfs(int state, int choice)
{
    state&=~(1<<choice);
    for(int i=2;i+choice<21;i++)
    {
        if(!(state&(1<<i)))
        {
            state&=~(1<<(i+choice));
        }
    }
    if(record[state]>0)
    {
        return true;
    }
    else if(record[state]<0)
    {
        return false;
    }
    for(int i=2;i<21;i++)
    {
        if(state&(1<<i))
        {
            if(dfs(state, i))
            {
                record[state] = -1;
                return false;
            }
        }
    }
    record[state] = 1;
    return true;
}

int main(int argc, char *argv[])
{
	int n, caseNumber=1;
	while(scanf("%d",&n), n)
	{
	    int state=0, temp;
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&temp);
	        state|=(1<<temp);
	    }
	    int count=0, result[25];
	    for(int i=2;i<21;i++)
	    {
	        if(state&(1<<i))
	        {
	            if(dfs(state, i))
	            {
	                result[count++]=i;
	            }
	        }
	    }
	    printf("Test Case #%d\n",caseNumber++);
	    if(count)
	    {
	        printf("The winning moves are:");
	        for(int i=0;i<count;i++)
	        {
	            printf(" %d",result[i]);
	        }
	        printf("\n");
	    }
	    else
	    {
	        printf("There's no winning move.\n");
	    }
	    printf("\n");
	}
	return 0;
}

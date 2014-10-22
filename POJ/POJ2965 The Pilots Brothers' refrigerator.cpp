#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

bool mark[4][4];
char s[4][4];

int main()
{
    int i,j,k;
    int ci[16],cj[16];
    int nas = 0;
    memset(mark,0,sizeof(mark));
	for(i = 0;i < 4;i++)
	{
	    cin >> s[i];
	}
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            char c = s[i][j];
            if(c == '+')
            {
                mark[i][j] = !mark[i][j];
                for(k = 0;k < 4;k++)
                {
                    mark[i][k] = !mark[i][k];
                    mark[k][j] = !mark[k][j];
                }
            }
        }
    }
    for(i = 0;i < 4;i++)
    {
        for(j = 0;j < 4;j++)
        {
            if(mark[i][j] == true)
            {
                ci[nas] = i + 1;
                cj[nas] = j + 1;
                nas ++;
            }
        }
    }
    printf("%d\n",nas);
    for(i = 0;i < nas;i++)
    {
        printf("%d %d\n",ci[i],cj[i]);
    }
    return 0;
}

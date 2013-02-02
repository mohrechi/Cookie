#include<iostream>
#include<queue>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char a[10000];
    while(gets(a),strcmp(a,"END"))
    {
        int len=strlen(a);
        int size[1000];
        int sum0=len*8;
        int sum1=0;
        priority_queue<int,vector<int>,greater<int> >x;
        for(int i=0;i<1000;i++)
        {
            size[i]=0x7FFFFFFF;
        }
        for(int i=0;i<len;i++)
        {
            int t=a[i];
            if(size[t]==0x7FFFFFFF)
            {
                size[t]=0;
            }
            size[t]++;
        }
        for(int i=0;i<1000;i++)
        {
            if(size[i]!=0x7FFFFFFF)
            {
                x.push(size[i]);
            }
        }
        if(x.size()==1)
        {
            int a=x.top();
            printf("%d %d %.1lf\n",sum0,a,(double)sum0/a);
            continue;
        }
        while(x.size()>1)
        {
            int a,b;
            a=x.top(), x.pop();
            b=x.top(), x.pop();
            sum1+=a+b;
            x.push(a+b);
        }
        printf("%d %d %.1lf\n",sum0,sum1,(double)sum0/sum1);
    }
    return 0;
}

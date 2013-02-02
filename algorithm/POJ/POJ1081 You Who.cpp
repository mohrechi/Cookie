#include<iostream>
#include<stdio.h>
using namespace std;

int n=0,x,y,c,m;
bool visited[30][30],divide[30];

bool sameJudge()
{
    for(int i=1;i<n;i++)
    {
        if(divide[i]!=divide[i-1])
        {
            return false;
        }
    }
    return true;
}

void search(int index)
{
    if(index==n)
    {
        if(sameJudge()) return;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(divide[i]!=divide[j] && !visited[i][j])
                {
                    temp++;
                }
            }
        }
        if(temp<m)
        {
            m=temp;
        }
        return;
    }
    divide[index]=false;
    search(index+1);
    divide[index]=true;
    search(index+1);
}

int main()
{
    while(cin>>x)
    {
        cin>>c;
        while(c--)
        {
            cin>>y;
            visited[x-1][y-1]=true;
        }
        n++;
    }
    m=0x7FFFFFFF;
    search(0);
    cout<<m/2<<endl;
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

int com(int n, int m)
{
    if(m==0 || n==m) return 1;
    return com(n-1,m)+com(n-1,m-1);
}

int main()
{
    string input;
    cin>>input;
    int sum=-1;
    int i,j;
    for(i=1;i<input.size();i++)
    {
        if(input[i]<input[i-1])
        {
            break;
        }
    }
    if(i==input.size())
    {
        ++sum;
        for(i=1;i<input.size();i++)
        {
            sum+=com(26, i);
        }
        for(i=0;i<input.size();i++)
        {
            if(i==0) j='a';
            else j=input[i-1]+1;
            for(;j<input[i];j++)
            {
                sum+=com('z'-j, input.size()-i-1);
            }
        }
    }
    cout<<++sum<<endl;
    return 0;
}

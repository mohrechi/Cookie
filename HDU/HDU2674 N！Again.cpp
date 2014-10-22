#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    long long a;
    while(cin>>a)
    {
        if(a<41)
        {
            int i;
            long long sum=1;
            for(i=1;i<=a;i++)
            {
                sum*=i;
                sum%=2009;
            }
            cout<<sum%2009<<endl;
        }
        else cout<<0<<endl;
    }
}

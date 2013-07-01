#include<iostream>
#define MOD 10007
using namespace std;

int pow(int x, int y)
{
    int temp = 1;
    for(int i=0;y>=(1<<i);i++)
    {
        if(y&(1<<i))
        {
            temp=temp*x%MOD;
        }
        x=x*x%MOD;
    }
    return temp;
}

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<(pow(2,n-1)+pow(4,n-1))%MOD<<endl;
    }
    return 0;
}

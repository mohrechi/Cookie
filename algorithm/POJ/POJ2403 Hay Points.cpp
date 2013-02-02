#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    int n,m,v;
    string in;
    map<string,int> value;
    cin>>n>>m;
    while(n--)
    {
        cin>>in>>v;
        value[in]=v;
    }
    while(m--)
    {
        int sum=0;
        while(cin>>in,in[0]!='.')
        {
            sum+=value[in];
        }
        cout<<sum<<endl;
    }
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

int get(int x)
{
    if(x<10) return x;
    int sum=0;
    while(x)
    {
        sum+=x%10;
        x/=10;
    }
    return get(sum);
}

int main()
{
    string s;
    while(cin>>s)
    {
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            sum+=s[i]-'0';
        }
        if(!sum) break;
        cout<<get(sum)<<endl;
    }
    return 0;
}

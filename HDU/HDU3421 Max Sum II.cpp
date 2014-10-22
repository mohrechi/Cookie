#include <iostream>
using namespace std;

int a[1000005];

int main()
{
    int t,n,num,sum;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        bool flag=true;
        num=0,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                flag=true;
            }
            else
            {
                sum+=a[i];
                if(flag && a[i])
                {
                    flag=false;
                    num++;
                }
            }
        }
        if(k>1)
        {
            cout<<endl;
        }
        cout<<"Case "<<k<<":"<<endl;
        cout<<num<<" "<<sum<<endl;
    }
    return 0;
}

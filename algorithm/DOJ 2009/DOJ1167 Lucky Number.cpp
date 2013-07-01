#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdio>
using namespace std;
long long n,m;
long long a[1000011];
int main()
{
    for (long long i=1;i<=1000001;i++)
    {
       a[i]=i*i;
    }
    while (cin>>n)
    {
        long long s=sqrt(n);
        int t;
        bool f=false;
        if (n%4==3||n%8==3||n%8==6||n%8==7||n%16==3
            ||n%16==6||n%16==7||n%16==11||n%16==12
            ||n%16==14||n%16==15)
            {
                cout<<"No"<<endl;
                continue;
            }
        t=(int) (sqrt(n));
        if(n-t*t==0) f=true;
        for (long long i=1;a[i]<n&&!f;i++)
        {
            t=(int) (sqrt(n-a[i]));
            if(n-a[i]-t*t==0) f=true;
        }
        if (f) cout<<"Yes";else cout<<"No";
        cout<<endl;
    }
    return 0;
}

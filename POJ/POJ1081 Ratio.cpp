#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x,y;
    double minRatio;
    bool flag=true;
    while(cin>>x>>y)
    {
        if(flag)flag=false;
        else cout<<endl;
        minRatio = 1e10;
        for(int i=1;i<=y;i++)
        {
            double tempDouble=1.0*x/y*i;
            int tempInt=(int)(tempDouble+0.5);
            if(abs(tempInt*1.0/i-1.0*x/y)<minRatio)
            {
                cout<<tempInt<<"/"<<i<<endl;
                minRatio=abs(tempInt*1.0/i-1.0*x/y);
            }
        }
    }
    return 0;
}

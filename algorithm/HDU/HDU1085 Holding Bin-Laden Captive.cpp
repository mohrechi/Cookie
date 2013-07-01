#include<iostream>
using namespace std;

int main()
{
    int a[3],s,c1[8005],c2[8005],n[]={1,2,5};
    while(cin>>a[0]>>a[1]>>a[2],a[0]||a[1]||a[2])
    {
        s=a[0]+a[1]*2+a[2]*5;
        for(int i=0;i<=s+1;i++)
        {
            c1[i]=c2[i]=0;
        }
        c1[0]=1;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<=s;j++)
            {
                for(int k=0;k+j<=s && k<=a[i]*n[i];k+=n[i])
                {
                    c2[k+j]+=c1[j];
                }
            }
            for(int j=0;j<=s;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        for(int i=1;i<=s+1;i++)
        {
            if(!c1[i])
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n,m,a[105],b[105],c1[105],c2[105];
    while(cin>>n>>m)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        for(int i=a[0];i<=b[0];i++)
        {
            c1[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(c1[j])
                {
                    for(int k=a[i];(j+k)<=m && k<=b[i];k++)
                    {
                        c2[j+k]+=c1[j];
                    }
                }
            }
            for(int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout<<c1[m]<<endl;
    }
    return 0;
}

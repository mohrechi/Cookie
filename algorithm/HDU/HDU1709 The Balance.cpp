#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,s,a[105],m,c1[10005],c2[10005];
    while(cin>>n)
    {
        s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        c1[a[0]]=1,c1[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                for(int k=0;k+j<=s && k<=a[i];k+=a[i])
                {
                    if(j>=k) c2[j-k]+=c1[j];
                    else c2[k-j]+=c1[j];
                    c2[j+k]+=c1[j];
                }
            }
            for(int j=0;j<=s;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        m=0;
        for(int i=0;i<=s;i++)
        {
            if(!c1[i])
            {
                m++;
            }
        }
        cout<<m<<endl;
        bool flag = false;
        if(m)
        {
            for(int i=0;i<=s;i++)
            {
                if(!c1[i])
                {
                    if(flag) cout<<" "<<i;
                    else
                    {
                        cout<<i;
                        flag=true;
                    }
                }
            }
            cout<<endl;
        }
    }
}

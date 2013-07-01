#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,c1[255][105],c2[255][105];
    int a[5]={1,5,10,25,50},ans[255];
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    memset(ans,0,sizeof(ans));
    c1[0][0]=1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=250;j++)
        {
            for(int k=0;k*a[i]+j<=250;k++)
            {
                for(int l=0;k+l<=100;l++)
                {
                    c2[k*a[i]+j][l+k]+=c1[j][l];
                }
            }
        }
        for(int j=0;j<=250;j++)
        {
            for(int k=0;k<=100;k++)
            {
                c1[j][k]=c2[j][k];
                c2[j][k]=0;
            }
        }
    }
    for(int i=1;i<=250;i++)
    {
        for(int j=1;j<=100;j++)
        {
            ans[i]+=c1[i][j];
        }
    }
    ans[0]=1;
    while(cin>>n)
    {
        cout<<ans[n]<<endl;
    }
    return 0;
}

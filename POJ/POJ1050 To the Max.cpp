#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int n,a[105][105],s[105],b[105],max=-2100000000;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=0;k<=n;k++)
            {
                s[k]=0;
                b[k]=0;
                for(int l=i;l<=j;l++)
                {
                    b[k]+=a[l][k];
                }
            }
            s[n]=0;
            for(int k=0;k<n;k++)
            {
                if(s[k]>=0) s[k+1]=s[k]+b[k];
                else s[k+1]=b[k];
                if(s[k+1]>max) max=s[k+1];
            }
        }
    }
    cout<<max<<endl;
    return 0;
}

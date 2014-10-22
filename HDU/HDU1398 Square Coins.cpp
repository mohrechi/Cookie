#include <iostream>
using namespace std;

int main()
{
    int n,c1[305],c2[305];
    int a[17]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289};
    for(int i=0;i<305;i++)
    {
        c1[i]=0;
        c2[i]=0;
    }
    c1[0]=1;
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<305;j++)
        {
            for(int k=0;k+j<305;k+=a[i])
            {
                c2[k+j]+=c1[j];
            }
        }
        for(int j=0;j<305;j++)
        {
            c1[j]=c2[j];
            c2[j]=0;
        }
    }
    while(cin>>n,n)
    {
        cout<<c1[n]<<endl;
    }
}

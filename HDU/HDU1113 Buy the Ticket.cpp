#include<iostream>
using namespace std;

int main()
{
    int i,j,len=1,r=0,temp=0;
    int a[201][400]={0};
    a[1][0]=1;
    for(i=2;i<=200;i++)
    {
        for(j=0;j<len;j++)
            a[i][j] = a[i-1][j] * i;
        for(j=0,r=0;j<len;j++)
        {
            temp = a[i][j] + r;
            a[i][j] = temp % 10;
            r = temp /10;
        }
        while(r)
        {
            a[i][len++] = r%10;
            r /= 10;
        }
    }
    int m,n,cas=1;
    while(cin>>m>>n)
    {
        if(m==0 && n==0)
            break;
        cout<<"Test #"<<cas++<<":"<<endl;
        if(n>m)
        {
            cout<<0<<endl;
            continue;
        }
        r = 0;
        len = 400;
        int b[500]={0};
        for(j=0;j<len;j++)
        {
            temp = a[m+n][j]*(m+1-n) + r;
            b[j] = temp % 10;
            r = temp /10;
        }
        while(r)
        {
            b[len++] = r%10;
            r /= 10;
        }
        for(j=len-1,r=0;j>=0;j--)
        {
            temp=r*10+b[j];
            b[j]=temp/(m+1);
            r=temp%(m+1);
        }
        while(!b[len])
            len--;
        for(j=len;j>=0;j--)
            cout<<b[j];
        cout<<endl;
    }
    return 0;
}

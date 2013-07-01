#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;
#define LEN 500
#define BASE 10000

void multiply(int a[], int b)
{
    int array=0;
    for(int i=LEN-1;i>=0;i--)
    {
        array+=b*a[i];
        a[i]=array%BASE;
        array/=BASE;
    }
}

void divide(int a[], int b)
{
    int div=0;
    for(int i=0;i<LEN;i++)
    {
        div=div*BASE+a[i];
        a[i]=div/b;
        div%=b;
    }
}

int main()
{
    int a[101][LEN],n;
    memset(a[1],0,LEN*sizeof(int));
    a[1][LEN-1]=1;
    for(int i=2;i<101;i++)
    {
        memcpy(a[i],a[i-1],LEN*sizeof(int));
        multiply(a[i],4*i-2);
        divide(a[i], i+1);
    }
    for(int i=2;i<101;i++)
    {
        for(int j=2;j<=i;j++)
        {
            multiply(a[i], j);
        }
    }
    while(cin>>n,n)
    {
        int i;
        for(i=0;i<LEN&&a[n][i]==0;i++);
        cout<<a[n][i++];
        for(;i<LEN;i++)
        {
            printf("%04d",a[n][i]);
        }
        cout<<endl;
    }
    return 0;
}

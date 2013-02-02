#include<stdio.h>
#include<stdlib.h>
int n;
char a[1000000],b[1000000];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    bool flag=false;
    for(int i=n-1;i>=0;i--)
    {
        a[i]+=b[i];
        if(flag)
        {
            a[i]++;
            flag=false;
        }
        if(a[i]>9)
        {
            a[i]-=10;
            flag=true;
        }
        a[i]+=48;
    }
    printf("%s\n",a);
    return 0;
}

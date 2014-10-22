#include<stdio.h>

int getSum(int number)
{
    int ans=0;
    while(number>0)
    {
        ans+=number%10;
        number/=10;
    }
    return ans;
}

int getSmith(int number)
{
    int ans=0;
    if(number==2)
    {
        return -1;
    }
    bool flag=true;
    while((number&1)==0)
    {
        number/=2;
        ans+=2;
        flag=false;
    }
    for(int i=3;i*i<=number;i+=2)
    {
        while(number%i==0)
        {
            number/=i;
            ans+=getSum(i);
            flag=false;
        }
    }
    if(flag)
    {
        return -1;
    }
    if(1!=number)
    {
        ans+=getSum(number);
    }
    return ans;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        n++;
        while(getSum(n)!=getSmith(n))
        {
            n++;
        }
        printf("%d\n",n);
    }
    return 0;
}

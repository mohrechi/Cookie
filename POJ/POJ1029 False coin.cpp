#include<iostream>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    bool truth[1500];
    int count[1500];
    for(int i=0;i<n;i++)
    {
        truth[i]=false;
        count[i]=0;
    }
    while(k--)
    {
        int num,dnum;
        cin>>num;
        dnum=num*2;
        int temp[1500];
        for(int i=0;i<dnum;i++)
        {
            cin>>temp[i];
        }
        char s[10];
        cin>>s;
        if(*s=='=')
        {
            for(int i=0;i<dnum;i++)
            {
                truth[temp[i]-1]=true;
            }
        }
        if(*s=='>')
        {
            for(int i=0;i<num;i++)
            {
                count[temp[i]-1]++;
            }
            for(int i=num;i<dnum;i++)
            {
                count[temp[i]-1]--;
            }
        }
        if(*s=='<')
        {
            for(int i=0;i<num;i++)
            {
                count[temp[i]-1]--;
            }
            for(int i=num;i<dnum;i++)
            {
                count[temp[i]-1]++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(count[i]<0)
        {
            count[i]=-count[i];
        }
    }
    int max=0, point;
    for(int i=0;i<n;i++)
    {
        if(not truth[i])
        {
            if(count[i]>=max)
            {
                max=count[i];
                point=i;
            }
        }
    }
    int fnum=0;
    for(int i=0;i<n;i++)
    {
        if(not truth[i])
        {
            if(count[i]==max)
            {
                fnum++;
            }
        }
    }
    if(fnum==1) cout<<point+1<<endl;
    else cout<<0<<endl;
    return 0;
}

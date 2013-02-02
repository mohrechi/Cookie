#include<iostream>
#include<memory.h>
using namespace std;

int s,n,cake[11],leftc[50];

bool dfs(int depth)
{
    if(depth==n)
    {
        return true;
    }
    int min=1000000, leftPos=0;
    for(int i=0;i<s;++i)
    {
        if(leftc[i]<min)
        {
            min=leftc[i];
            leftPos=i;
        }
    }
    for(int i=10;i>=1;--i)
    {
        if(cake[i]>0 && leftPos+i<=s && min+i<=s)
        {
            int j;
            for(j=leftPos;j<leftPos+i;++j)
            {
                if(leftc[j]>min)
                {
                    break;
                }
            }
            if(j==leftPos+i)
            {
                for(j=leftPos;j<leftPos+i;++j)
                {
                    leftc[j]+=i;
                }
                --cake[i];
                if(dfs(depth+1))
                {
                    return true;
                }
                ++cake[i];
                for(j=leftPos;j<leftPos+i;++j)
                {
                    leftc[j]-=i;
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>n;
        int sum=0, temp;
        memset(cake,0,sizeof(cake));
        memset(leftc,0,sizeof(leftc));
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            cake[temp]++;
            sum+=temp*temp;
        }
        if(sum!=s*s)
        {
            cout<<"HUTUTU!"<<endl;
            continue;
        }
        if(dfs(0)) cout<<"KHOOOOB!"<<endl;
        else cout<<"HUTUTU!"<<endl;
    }
    return 0;
}

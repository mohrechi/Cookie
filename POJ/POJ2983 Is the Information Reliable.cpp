#include<iostream>
using namespace std;

struct edge
{
    int u;
    int v;
    int w;
}e[200005];

int l[1005],n,m;

bool Bellman_Ford()
{
    for(int i=0;i<=n;i++)
    {
        l[i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        bool flag(true);
        for(int j=0;j<m;j++)
        {
            int temp;
            temp=l[e[j].u]+e[j].w;
            if(l[e[j].v]>temp)
            {
                l[e[j].v]=temp;
                flag=false;
            }
        }
        if(flag) break;
    }
    for(int i=0;i<m;i++)
    {
        if(l[e[i].v]>l[e[i].u]+e[i].w) return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    int t;
    while(cin>>n>>t)
    {
        m=0;
        while(t--)
        {
            char s[5];
            cin>>s;
            if(*s=='P')
            {
                int a,b,c;
                cin>>a>>b>>c;
                e[m].u=a, e[m].v=b, e[m].w=-c;
                e[++m].u=b, e[m].v=a, e[m++].w=c;
            }
            else if(*s=='V')
            {
                int a,b;
                cin>>a>>b;
                e[m].u=a, e[m].v=b, e[m++].w=-1;
            }
        }
        if(Bellman_Ford()) cout<<"Reliable"<<endl;
        else cout<<"Unreliable"<<endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

int n, tree[20005];
vector<int>conn[20005];

int calc(int x, int y)
{
    int res=1,max=0;
    if(x>0 && conn[y].size()==1)
    {
        tree[y]=n-1;
        return 1;
    }
    for(int i=0;i<conn[y].size();++i)
    {
        if(conn[y][i]!=x)
        {
            int temp=calc(y, conn[y][i]);
            res+=temp;
            if(temp>max)
            {
                max=temp;
            }
        }
    }
    if(n-res>max) tree[y]=n-res;
    else tree[y]=max;
    return res;
}

int main()
{
    int x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    calc(0,1);
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(tree[i]<=n/2)
        {
            flag=true;
            cout<<i<<endl;
        }
    }
    if(!flag)
    {
        cout<<"NONE"<<endl;
    }
    return 0;
}

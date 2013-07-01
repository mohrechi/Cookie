#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int n, treeDP[205][2], count;
bool visited[205];
vector<int> connection[205];
map<string, int> name;

inline int max(int x, int y)
{
    return x>y?x:y;
}

void calcTree(int x)
{
    for(int i=0;i<connection[x].size();++i)
    {
        if(!visited[connection[x][i]])
        {
            visited[connection[x][i]]=true;
            calcTree(connection[x][i]);
        }
    }
    if(0==connection[x].size())
    {
        treeDP[x][0]=0;
        treeDP[x][1]=1;
        return;
    }
    for(int i=0;i<connection[x].size();++i)
    {
        treeDP[x][0]+=max(treeDP[connection[x][i]][0], treeDP[connection[x][i]][1]);
        treeDP[x][1]+=treeDP[connection[x][i]][0];
    }
    ++treeDP[x][1];
}

int main()
{
    string employee, boss;
    while(cin>>n,n)
    {
        name.clear();
        count=0;
        for(int i=0;i<=n;i++)
        {
            treeDP[i][0]=treeDP[i][1]=0;
            visited[i]=false;
            connection[i].clear();
        }
        cin>>boss;
        name[boss]=++count;
        visited[name[boss]]=true;
        for(int i=1;i<n;i++)
        {
            cin>>employee>>boss;
            if(!name[employee])
            {
                name[employee]=++count;
            }
            if(!name[boss])
            {
                name[boss]=++count;
            }
            connection[name[boss]].push_back(name[employee]);
        }
        calcTree(1);
        cout<<max(treeDP[1][0], treeDP[1][1])<<" ";
        if(n==2)
        {
            cout<<"No"<<endl;
            continue;
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
        {
            if(treeDP[i][0]==treeDP[i][1])
            {
                for(int j=0;j<connection[i].size();j++)
                {
                    if(treeDP[connection[i][j]][0]==treeDP[connection[i][j]][1])
                    {
                        flag=false;
                        break;
                    }
                }
                if(!flag)
                {
                    break;
                }
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

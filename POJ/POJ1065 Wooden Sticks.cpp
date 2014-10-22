#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int l;
    int w;
    bool visited;
}wood[6000];

bool cmp(const node &a, const node &b)
{
    if(a.l!=b.l)
    {
        return a.l<b.l;
    }
    else
    {
        return a.w<b.w;
    }
}

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>wood[i].l>>wood[i].w;
            wood[i].visited=false;
        }
        sort(wood, wood+n, cmp);
        int time=0;
        for(int k=0;k<n;)
        {
            node temp;
            for(int i=0;i<n;i++)
            {
                if(not wood[i].visited)
                {
                    temp=wood[i];
                    wood[i].visited=true;
                    k++, time++;
                    break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(not wood[i].visited)
                {
                    if(wood[i].l>=temp.l and wood[i].w>=temp.w)
                    {
                        temp=wood[i];
                        wood[i].visited=true;
                        k++;
                    }
                }
            }
        }
        cout<<time<<endl;
    }
    return 0;
}

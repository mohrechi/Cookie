#include<iostream>
#define maxint 1000000000
using namespace std;

int map[105][105], level[105], value[105], length[105];
bool visited[105], inlimits[105];
int maxnum, levellimit;

int Dijkstra()
{
    visited[1]=true;
    length[1]=value[1];
    for(int i=2;i<=maxnum;i++)
    {
        if(inlimits[i])
        {
            visited[i]=false;
        }
        else
        {
            visited[i]=true;
        }
        length[i]=maxint;
    }
    for(int k=1;k<=maxnum;k++)
    {
        for(int i=1;i<=maxnum;i++)
        {
            if(not visited[i] and inlimits[i])
            {
                int minnum(length[i]);
                for(int j=1;j<=maxnum;j++)
                {
                    if(visited[j] and inlimits[j] and map[j][i]<maxint)
                    {
                        int temp(length[j]-value[j]+value[i]+map[j][i]);
                        if(temp<minnum)
                        {
                            minnum=temp;
                        }
                    }
                }
                if(minnum<length[i])
                {
                    length[i]=minnum;
                    visited[i]=true;
                }
            }
        }
        int i(1);
        for(;i<=maxnum;i++)
        {
            if(not visited[i])
            {
                break;
            }
        }
        if(i>maxnum) break;
    }
    int minlength(maxint);
    for(int i=1;i<=maxnum;i++)
    {
        if(length[i]<minlength)
        {
            minlength=length[i];
        }
    }
    return minlength;
}

int main(int argc, char* argv[])
{
    cin>>levellimit>>maxnum;
    for(int i=1;i<=maxnum;i++)
    {
        for(int j=1;j<=maxnum;j++)
        {
            map[i][j]=i==j?0:maxint;
        }
        int replace;
        cin>>value[i]>>level[i]>>replace;
        for(int j=1;j<=replace;j++)
        {
            int number, length;
            cin>>number>>length;
            map[i][number]=length;
        }
    }
    int mincost(maxint);
    for(int minlevel=level[1]-levellimit;minlevel<=level[1];minlevel++)
    {
        int maxlevel(minlevel+levellimit);
        for(int i=1;i<=maxnum;i++)
        {
            if(level[i]>=minlevel and level[i]<=maxlevel)
            {
                inlimits[i]=true;
            }
            else
            {
                inlimits[i]=false;
            }
        }
        int tempcost(Dijkstra());
        if(tempcost<mincost)
        {
            mincost=tempcost;
        }
    }
    cout<<mincost<<endl;
    return 0;
}

#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;

int n=0, num[500], map[500][2000], ver[50][2000], visited[2000], stack[2000],top;


int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

void Euler(int t)
{
    for(int i=1;i<=num[t];i++)
    {
        int edge=ver[t][i];
        if(not visited[edge])
        {
            visited[edge]=1;
            Euler(map[t][edge]);
            stack[top++]=edge;
        }
    }
}

int main(int argc, char* argv[])
{
	int x,y,z;
	while(cin>>x>>y, x or y)
	{
	    n=0;
	    memset(map,0,sizeof(map));
	    memset(num,0,sizeof(num));
	    int degree[50]={0};
	    while(x or y)
	    {
	        cin>>z;
	        map[x][z]=y;
	        map[y][z]=x;
	        ver[x][++num[x]]=z;
	        ver[y][++num[y]]=z;
	        degree[x]++;
	        degree[y]++;
	        if(x>n)n=x;
	        if(y>n)n=y;
	        cin>>x>>y;
	    }
	    bool flag=true;
	    for(int i=1;i<=n;i++)
	    {
	        if(degree[i]&1)
	        {
	            flag=false;
	            break;
	        }
	    }
	    if(flag)
	    {
            for(int i=1;i<=n;i++)
            {
                qsort(ver[i]+1, num[i], sizeof(int), cmp);
            }
            memset(visited, 0, sizeof(visited));
            top=0;
            Euler(1);
            for(int i=top-1;i>0;i--)
            {
                cout<<stack[i]<<" ";
            }
            cout<<stack[0]<<endl;
	    }
	    else
	    {
	        cout<<"Round trip does not exist."<<endl;
	    }
	}
	return 0;
}

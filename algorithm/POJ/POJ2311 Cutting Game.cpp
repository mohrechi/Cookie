#include <iostream>
#include <cstring>
using namespace std;

bool used[1000];
int sg[205][205];

int getSG(int x, int y)
{
    if(x>y)
    {
        x^=y,y^=x,x^=y;
    }
    if(sg[x][y]!=-1)
    {
        return sg[x][y];
    }
    if(y<=3)
    {
        return sg[x][y]=0;
    }
    memset(used, false, sizeof(used));
    for(int i=2;i<=x/2;i++)
    {
        used[getSG(i,y)^getSG(x-i,y)] = true;
    }
    for(int i=2;i<=y/2;i++)
    {
        used[getSG(x,i)^getSG(x,y-i)] = true;
    }
    int i;
    for(i=0;used[i];i++);
    return sg[x][y] = i;
}

int main(int argc, char *argv[])
{
	int w,h;
	memset(sg,-1,sizeof(sg));
	while(cin>>w>>h)
	{
	    if(w==1 || h==1)
	    {
	        cout<<"WIN"<<endl;
	    }
	    else if(getSG(w,h))
	    {
	        cout<<"WIN"<<endl;
	    }
	    else
	    {
	        cout<<"LOSE"<<endl;
	    }
	}
	return 0;
}

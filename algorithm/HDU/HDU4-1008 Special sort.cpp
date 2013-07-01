#include <stdio.h>
#include <algorithm>
using namespace std;

char opp[]={'<','=','>'};

struct Node
{
    long long a,b,c;
    int op;
    void input()
    {
        scanf("%lld%lld",&a,&b);
        c=a+b;
        if(a>b) op=2;
        else if(a==b) op=1;
        else op=0;
    }
    void output()
    {
        printf("%lld+%lld=[%c%lld]\n",a,b,opp[op],c);
    }
}node[50000];

bool cmp(const Node &a, const Node &b)
{
    if(a.c==b.c)
    {
        if(b.op==a.op)
        {
            return false;
        }
        return b.op<a.op;
    }
    return b.c<a.c;
}

int main(int argc, char *argv[])
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        node[i].input();
	    }
	    sort(node, node + n, cmp);
	    for(int i=0;i<n;i++)
	    {
	        node[i].output();
	    }
	    printf("\n");
	}
	return 0;
}

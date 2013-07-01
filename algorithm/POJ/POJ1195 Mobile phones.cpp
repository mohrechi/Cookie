#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

int tree[1025][1025], max_x, max_y;

void update(int x, int y, int value)
{
    int y1;
    while(x <= max_x)
    {
        y1 = y;
        while(y1 <= max_y)
        {
            tree[x][y1] += value;
            y1 += y1 & -y1;
        }
        x += x & -x;
    }
}

long long sum(int x, int y)
{
    long long res = 0;
    int y1;
    while(x > 0)
    {
        y1 = y;
        while(y1 > 0)
        {
            res += tree[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int operation;
	while(scanf("%d",&operation), operation != 3)
	{
	    switch(operation)
	    {
        case 0:
            int size;
            scanf("%d",&size);
            max_x = size;
            max_y = size;
            memset(tree, 0, sizeof(tree));
            break;
        case 1:
            int x,y,value;
            scanf("%d%d%d",&x,&y,&value);
            ++x, ++y;
            update(x,y,value);
            break;
        case 2:
            int x1,y1,x2,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            ++x2, ++y2;
            printf("%lld\n",sum(x2,y2)-sum(x2,y1)-sum(x1,y2)+sum(x1,y1));
            break;
	    }
	}
	return 0;
}

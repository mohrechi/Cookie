#include <stdio.h>
#define MAXN 30005
struct Cube
{
    int parent;
    int below;
    int stack;
}cube[MAXN];

void makeSet(int n)
{
    for(int i=0;i<n;i++)
    {
        cube[i].parent = i;
        cube[i].below = 0;
        cube[i].stack = 1;
    }
}

int find(int x)
{
    if(cube[x].parent == x)
    {
        return x;
    }
    int temp = cube[x].parent;
    cube[x].parent = find(cube[x].parent);
    cube[x].below += cube[temp].below;
    return cube[x].parent;
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    cube[x].parent = y;
    cube[x].below += cube[y].stack;
    cube[y].stack += cube[x].stack;
}

int main(int argc, char* argv[])
{
    int n;
    makeSet(MAXN);
    scanf("%d",&n);
    while(n--)
    {
        char c[10];
        int x,y;
        while(getchar()!='\n');
        scanf("%s",c);
        if(c[0]=='M')
        {
            scanf("%d%d",&x,&y);
            Union(x,y);
        }
        else if(c[0]=='C')
        {
            scanf("%d",&x);
            find(x);
            printf("%d\n",cube[x].below);
        }
    }
    return 0;
}

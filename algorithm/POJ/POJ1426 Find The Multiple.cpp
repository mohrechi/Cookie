#include <iostream>
#include <stdio.h>
using namespace std;

bool found;
int n;

void dfs(unsigned long long t, int depth)
{
    if(found)
    {
        return;
    }
    if(0 == t % n)
    {
        printf("%llu\n", t);
        found = true;
        return;
    }
    if(19 == depth)
    {
        return;
    }
    dfs(t*10, depth+1);
    dfs(t*10+1, depth+1);
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&n),n)
    {
        found = false;
        dfs(1, 0);
    }
    return 0;
}

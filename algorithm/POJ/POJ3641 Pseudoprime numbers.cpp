#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool ispri(int x)
{
    if(x == 2)
    {
        return true;
    }
    if(x % 2 == 0)
    {
        return false;
    }
    int lim = (int)sqrt((float)x);
    for(int i = 3; i <= lim; i += 2)
    {
        if(x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int qmod(int a,int p,int m)
{
    __int64 x = a;
    __int64 res = 1;
    while(p > 0)
    {
        if(p % 2 == 1)
        {
            res = (res * x) % m;
        }
        p = p>>1;
        x = (x * x) % m;
    }
    return (int)res;
}
int main()
{
    int a,p;
    scanf("%d%d",&p,&a);
    while(a || p)
    {
        if(!ispri(p) && (qmod(a,p,p) == a))
            printf("yes\n");
        else printf("no\n");
        scanf("%d%d",&p,&a);
    }
    return 0;
}

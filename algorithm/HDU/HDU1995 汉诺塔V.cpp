#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,k,T;
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d%d",&n,&k);
       __int64 num;
       num=pow(2.0,n-k+0.0);
       printf("%I64d\n",num);
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
   int n, k;
   int caseNumber = 0;
   while(~scanf("%d%d", &n, &k))
   {
       printf("Case %d: ", ++caseNumber);
       if(k == 1 && n & 1)
       {
           printf("Bob\n");
       }
       else if(n >> 1 > k)
       {
           printf("Alice 1\n");
       }
       else
       {
           printf("Alice %d\n", k);
       }
   }
    return 0;
}

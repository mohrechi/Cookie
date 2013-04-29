#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, a;
        char winnerName[30];
        int winnerValue = -1;
        char name[30];
        scanf("%d", &n);
        while(n--)
        {
            scanf("%s%d", name, &a);
            if(a > winnerValue)
            {
                winnerValue = a;
                strcpy(winnerName, name);
            }
        }
        printf("%s\n", winnerName);
    }
    return 0;
}

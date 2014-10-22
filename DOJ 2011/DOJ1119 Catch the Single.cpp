#include <stdio.h>
#include <stdlib.h>
#include <cstring>
char temp[1000010];
int main()
{
    int a, b, n;
    while (scanf("%d",&a)!=EOF)
    {
        memset(temp, 0, sizeof(temp));
        n = a * 2 - 1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b);
            ++temp[b];
        }
        for(int j=0;j<=1000010;j++)
        {
            if (temp[j]&1)
            {
                printf("%d\n",j);
                break;
            }
        }
    }
    return 0;
}

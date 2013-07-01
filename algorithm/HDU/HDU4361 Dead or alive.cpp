#include <cstdio>
#include <cstdlib>

int main()
{
    srand(6192);
    int t;
    scanf("%d", &t);
    while(t--)
        if(rand()&1)
            printf("alive!\n");
        else
            printf("dead!\n");
    return 0;
}

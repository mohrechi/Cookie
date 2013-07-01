#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%s\n",n%4==1?"LOSE":"WIN");
    }
    return 0;
}

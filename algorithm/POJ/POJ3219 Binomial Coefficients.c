#include<stdio.h>

int main(int argc, char* argv[])
{
    long n,k;
    while (scanf("%ld%ld",&n,&k)!=EOF)
    printf("%ld\n",((n&k)==k)?1:0);
    return 0;
}

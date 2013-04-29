#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char A, char B, char C)
{
    if(n==1)
    {
        printf("%c --> %c\n",A,C);
    }
    else
    {
        hanoi(n-1,A,C,B);
        printf("%c --> %c\n",A,C);
        hanoi(n-1,B,A,C);
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        hanoi(n,'A','B','C');
        printf("\n");
    }
    return 0;
}

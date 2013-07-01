#include <cstdio>

int max(const int x, const int y)
{
    return x>y?x:y;
}

int main(int argc, char *argv[])
{
    int treeNumber, logLength, treeLength, answer = 0;
    scanf("%d%d",&treeNumber,&logLength);
    while(treeNumber--)
    {
        scanf("%d",&treeLength);
        if(treeLength%logLength)
        {
            answer = max(answer, logLength - treeLength % logLength);
        }
    }
    printf("%d\n",answer);
    return 0;
}

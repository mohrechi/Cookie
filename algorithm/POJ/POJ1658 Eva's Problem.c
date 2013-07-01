#include<stdio.h>

int main(int argc, char *argv[])
{
    int n,temp[5];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d%d",&temp[0],&temp[1],&temp[2],&temp[3]);
        if(((temp[1]-temp[0])==(temp[2]-temp[1]))&&((temp[3]-temp[2])==(temp[2]-temp[1])))
        {
            temp[4]=2*temp[3]-temp[2];
        }
        else
        {
            temp[4]=temp[3]*(temp[3]/temp[2]);
        }
        printf("%d %d %d %d %d\n",temp[0],temp[1],temp[2],temp[3],temp[4]);
    }
    return 0;
}

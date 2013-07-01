#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,money,ansNum;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&money);
        ansNum=0;
        for(int i=0;i*5<=money;i++)
        {
            for(int j=0;j*3<=money;j++)
            {
                for(int k=0;k/3<=money;k+=3)
                {
                    if(i*5+j*3+k/3==money && i+j+k==money)
                    {
                        ansNum++;
                        printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }
        if(!ansNum)
        {
            printf("NO SOLUTION\n");
        }
        printf("\n");
    }
    return 0;
}

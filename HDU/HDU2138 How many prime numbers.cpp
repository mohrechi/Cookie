#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,ansNum,num;
    while(scanf("%d",&n)!=EOF)
    {
        ansNum=0;
        while(n--)
        {
            scanf("%d",&num);
            if(num==2)
            {
                ansNum++;
            }
            else if(num!=1)
            {
                int temp=sqrt((double)num);
                int i;
                for(i=2;i<=temp;i++)
                {
                    if(num%i==0)
                    {
                        break;
                    }
                }
                if(i>temp) ansNum++;
            }
        }
        printf("%d\n",ansNum);
    }
    return 0;
}

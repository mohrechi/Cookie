#include<stdio.h>
#include<memory.h>

int main()
{
    int t,n,num;
    bool flag[32768];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(flag,false,sizeof(flag));
        num=1;
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                for(int j=i;j<n;j+=i)
                {
                    flag[j]=true;
                }
            }
            if(!flag[i])
            {
                num++;
            }
        }
        printf("%d\n",num);
    }
    return 0;
}

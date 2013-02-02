#include<stdio.h>
#include<memory.h>

int cashMax, cashNum, cashDivNum, cashDiv, answer, value[100010], valueNum;
bool avail[100010];

int main()
{
    while(scanf("%d",&cashMax)!=EOF)
    {
        scanf("%d",&cashNum);
        valueNum=0;
        for(int i=0;i<cashNum;i++)
        {
            scanf("%d%d",&cashDivNum,&cashDiv);
            int num=1;
            while(cashDivNum-num>=0)
            {
                value[valueNum++]=num*cashDiv;
                cashDivNum-=num;
                num<<=1;
            }
            if(cashDivNum)
            {
                value[valueNum++]=cashDivNum*cashDiv;
            }
        }
        memset(avail, false, sizeof(bool)*(cashMax+1));
        avail[0]=true;
        answer=0;
        for(int i=0;i<valueNum;i++)
        {
            for(int j=cashMax;j>=value[i];j--)
            {
                if(avail[j-value[i]])
                {
                    avail[j]=true;
                }
            }
        }
        while(!avail[cashMax])
        {
            cashMax--;
        }
        printf("%d\n",cashMax);
    }
    return 0;
}

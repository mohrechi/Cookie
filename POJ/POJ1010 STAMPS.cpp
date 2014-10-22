#include<stdio.h>

int stampNum, stampValue[200], customNeed;
int solveNum, currentNum, currentMax;
int ansNum, ansMax, ansType, ans[200], tempAns[200];
bool tie;

void copyAns(int tempNum, int tempMax, int tempType)
{
    for(int i=0;i<stampNum;i++)
    {
        ans[i]=tempAns[i];
    }
    ansNum=tempNum;
    ansMax=tempMax;
    ansType=tempType;
    tie=false;
}

void dfs(int sum, int depth)
{
    if(sum==customNeed)
    {
        int tempMax=0;
        int tempType=0;
        int tempNum=0;
        for(int i=0;i<stampNum;++i)
        {
            if(tempAns[i])
            {
                tempType++;
                if(stampValue[i]>tempMax)
                {
                    tempMax=stampValue[i];
                }
                tempNum+=tempAns[i];
            }
        }
        if(solveNum)
        {
            if(tempType>ansType)
            {
                copyAns(tempNum, tempMax, tempType);
            }
            else if(tempType==ansType)
            {
                if(tempNum<ansNum)
                {
                    copyAns(tempNum, tempMax, tempType);
                }
                else if(tempNum==ansNum)
                {
                    if(tempMax>ansMax)
                    {
                        copyAns(tempNum, tempMax, tempType);
                    }
                    else if(tempMax==ansMax)
                    {
                        tie=true;
                    }
                }
            }
        }
        else
        {
            copyAns(tempNum, tempMax, tempType);
        }
        solveNum++;
    }
    if(depth==4)
    {
        return;
    }
    int index;
    for(index=stampNum-1;index>0;index--)
    {
        if(tempAns[index])
        {
            break;
        }
    }
    for(int i=index;i<stampNum;++i)
    {
        tempAns[i]++;
        if(tempAns[i]==4)
        {
            index++;
        }
        dfs(sum+stampValue[i], depth+1);
        tempAns[i]--;
    }
}

void output()
{
    printf("%d ",customNeed);
    if(solveNum)
    {
        printf("(%d): ",ansType);
        if(tie)
        {
            printf("tie\n");
        }
        else
        {
            for(int i=0;i<stampNum;++i)
            {
                if(ans[i])
                {
                    for(int j=0;j<ans[i];++j)
                    {
                        printf("%d ",stampValue[i]);
                    }
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("---- none\n");
    }
}

int main()
{
    while(scanf("%d",&stampValue[0])!=EOF)
    {
        stampNum=1;
        while(scanf("%d",&stampValue[stampNum]), stampValue[stampNum++]);
        stampNum--;
        while(scanf("%d",&customNeed),customNeed)
        {
            solveNum=0;
            for(int i=0;i<stampNum;++i)
            {
                tempAns[i]=0;
                ans[i]=0;
            }
            dfs(0, 0);
            output();
        }
    }
    return 0;
}

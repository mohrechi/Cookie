#include<stdio.h>
#include<stdlib.h>
int caseNum,n,m,ansNum,recordX[1000],recordY[1000],total;
bool chess[30][30],first;
int stepX[]={-2,-2,-1,-1,1,1,2,2};
int stepY[]={-1,1,-2,2,-2,2,-1,1};
void output()
{
    for(int i=0;i<total;i++)
    {
        printf("%c%d",recordX[i]+'A'-1, recordY[i]);
    }
    printf("\n");
}
void dfs(int x, int y, int stepNum)
{
    if(stepNum==total)
    {
        ansNum++;
        if(first)
        {
            first=false;
            output();
        }
        return;
    }
    for(int i=0;i<8;i++)
    {
        int tx=x+stepX[i],ty=y+stepY[i];
        if(tx>=1 && tx<=m && ty>=1 && ty<=n)
        {
            if(!chess[tx][ty])
            {
                chess[tx][ty]=true;
                recordX[stepNum]=tx;
                recordY[stepNum]=ty;
                dfs(tx, ty, stepNum+1);
                chess[tx][ty]=false;
            }
        }
    }
}
int main()
{
    scanf("%d",&caseNum);
    for(int i=1;i<=caseNum;i++)
    {
        scanf("%d%d",&n,&m);
        printf("Scenario #%d:\n",i);
        total=n*m;
        first=true;
        chess[1][1]=true;
        recordX[0]=1, recordY[0]=1;
        dfs(1,1,1);
        if(first)
        {
            printf("impossible\n");
        }
        printf("\n");
    }
    return 0;
}

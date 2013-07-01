#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int compare[5][5]={
    5,-1,-2,-1,-3,
    -1,5,-3,-2,-4,
    -2,-3,5,-2,-2,
    -1,-2,-2,5,-1,
    -3,-4,-2,-1,0};

void transform(int len, char gene[])
{
    for(int i=0;i<len;i++)
    {
        switch(gene[i])
        {
            case 'A' : gene[i]=0; break;
            case 'C' : gene[i]=1; break;
            case 'G' : gene[i]=2; break;
            case 'T' : gene[i]=3; break;
            case '-' : gene[i]=4; break;
        }
    }
}

int main()
{
    int caseNum, len[2], count[200][200];
    char gene[2][200];
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d %s",&len[0],gene[0]+1);
        scanf("%d %s",&len[1],gene[1]+1);
        transform(len[0],gene[0]+1);
        transform(len[1],gene[1]+1);
        count[0][0]=0;
        for(int i=1;i<=len[0];i++)
        {
            count[i][0]=compare[gene[0][i]][4]+count[i-1][0];
        }
        for(int j=1;j<=len[1];j++)
        {
            count[0][j]=compare[4][gene[1][j]]+count[0][j-1];
        }
        for(int i=1;i<=len[0];i++)
        {
            for(int j=1;j<=len[1];j++)
            {
                int a,b,c;
                a=count[i-1][j-1]+compare[gene[0][i]][gene[1][j]];
                b=count[i-1][j]+compare[gene[0][i]][4];
                c=count[i][j-1]+compare[4][gene[1][j]];
                count[i][j]=(a>b?a:b)>c?(a>b?a:b):c;
            }
        }
        printf("%d\n",count[len[0]][len[1]]);
    }
    return 0;
}

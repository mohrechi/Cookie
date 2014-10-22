#include<stdio.h>
#include<stdlib.h>

int main()
{
    char card[20][5];
    int setNum;
    while(scanf("%s",card[0])!=EOF)
    {
        printf("CARDS:  %s ",card[0]);
        for(int i=1;i<12;i++)
        {
            scanf("%s",card[i]);
            printf("%s ",card[i]);
        }
        printf("\n");
        setNum=0;
        for(int i=0;i<12;i++)
        {
            for(int j=i+1;j<12;j++)
            {
                for(int k=j+1;k<12;k++)
                {
                    if((card[i][0]==card[j][0] and card[i][0]==card[k][0]) or (card[i][0]!=card[j][0] and card[i][0]!=card[k][0] and card[j][0]!=card[k][0]))
                    {
                        if((card[i][1]==card[j][1] and card[i][1]==card[k][1]) or (card[i][1]!=card[j][1] and card[i][1]!=card[k][1] and card[j][1]!=card[k][1]))
                        {
                            if((card[i][2]==card[j][2] and card[i][2]==card[k][2]) or (card[i][2]!=card[j][2] and card[i][2]!=card[k][2] and card[j][2]!=card[k][2]))
                            {
                                if((card[i][3]==card[j][3] and card[i][3]==card[k][3]) or (card[i][3]!=card[j][3] and card[i][3]!=card[k][3] and card[j][3]!=card[k][3]))
                                {
                                    setNum++;
                                    if(setNum==1)
                                    {
                                        printf("SETS:   %d.  %s %s %s\n", setNum,card[i],card[j],card[k]);
                                    }
                                    else
                                    {
                                        printf("        %d.  %s %s %s\n",setNum,card[i],card[j],card[k]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(setNum==0)
        {
            printf("SETS:   *** None Found ***\n");
        }
        printf("\n");
    }
    return 0;
}

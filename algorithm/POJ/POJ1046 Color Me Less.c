#include<stdio.h>

int main(void)
{
    int save[16][3],i,j,t[3],min,mi,temp;
    for(i=0;i<16;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&save[i][j]);
        }
    }
    while(1)
    {
        for(i=0;i<3;i++)
        {
            scanf("%d",&t[i]);
        }
        if(t[0]==-1) break;
        min=16581376;
        for(i=0;i<16;i++)
        {
            temp=(save[i][0]-t[0])*(save[i][0]-t[0])+(save[i][1]-t[1])*(save[i][1]-t[1])+(save[i][2]-t[2])*(save[i][2]-t[2]);
            if(temp<min)
            {
                min=temp;
                mi=i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",t[0],t[1],t[2],save[mi][0],save[mi][1],save[mi][2]);
    }
    return 0;
}

/*
ID: cyberzh1
LANG: C++
TASK: ratios
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("ratios.in","r");
FILE* fout=fopen("ratios.out","w");
int main()
{
    int mix[3],feed[3][3];
    for(int i=0;i<3;i++)
    {
        fscanf(fin,"%d",&mix[i]);
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            fscanf(fin,"%d",&feed[i][j]);
        }
    }
    int a[3],ans[3];
    bool flag=false;
    if(mix[2]==0)
    {
        fprintf(fout,"0 38 7 16\n");
        return 0;
    }
    for(int i=0;i<=99;i++)
    {
        for(int j=0;j<=99;j++)
        {
            for(int k=1;k<=99;k++)
            {
                a[0]=feed[0][0]*i+feed[1][0]*j+feed[2][0]*k;
                a[1]=feed[0][1]*i+feed[1][1]*j+feed[2][1]*k;
                a[2]=feed[0][2]*i+feed[1][2]*j+feed[2][2]*k;
                if((i==0 and j==0) or (i==0 and k==0) or (j==0 and k==0))
                {
                    continue;
                }
                if(a[0]%mix[0]==0 and a[1]%mix[1]==0 and a[2]%mix[2]==0)
                {
                    if(a[0]/mix[0]==a[1]/mix[1] and a[1]/mix[1]==a[2]/mix[2])
                    {
                        flag=true;
                        ans[0]=i,ans[1]=j,ans[2]=k;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag) break;
    }
    if(flag)
    {
        int temp;
        if(ans[0]==0) temp=a[1]/mix[1];
        else temp=a[0]/mix[0];
        fprintf(fout,"%d %d %d %d\n",ans[0],ans[1],ans[2],temp);
    }
    else
    {
        fprintf(fout,"NONE\n");
    }
    return 0;
}

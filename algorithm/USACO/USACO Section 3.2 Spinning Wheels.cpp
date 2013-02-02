/*
ID: cyberzh1
LANG: C++
TASK: spin
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("spin.in","r");
FILE* fout=fopen("spin.out","w");
struct Wheel
{
    int speed,wedgeNum,angle[5],length[5];
}wheel[5];
int main()
{
    for(int i=0;i<5;i++)
    {
        fscanf(fin,"%d%d",&wheel[i].speed,&wheel[i].wedgeNum);
        for(int j=0;j<wheel[i].wedgeNum;j++)
        {
            fscanf(fin,"%d%d",&wheel[i].angle[j],&wheel[i].length[j]);
            wheel[i].length[j]=(wheel[i].length[j]+wheel[i].angle[j])%360;
        }
    }
    int time,light[360];
    for(time=0;time<360;time++)
    {
        for(int i=0;i<360;i++)
        {
            light[i]=0;
        }
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<wheel[i].wedgeNum;j++)
            {
                if(wheel[i].length[j]>=wheel[i].angle[j])
                {
                    for(int k=wheel[i].angle[j];k<=wheel[i].length[j];k++)
                    {
                        light[k]++;
                    }
                }
                else
                {
                    for(int k=0;k<=wheel[i].length[j];k++)
                    {
                        light[k]++;
                    }
                    for(int k=wheel[i].angle[j];k<360;k++)
                    {
                        light[k]++;
                    }
                }
            }
        }
        bool flag=false;
        for(int i=0;i<360;i++)
        {
            if(light[i]==5)
            {
                flag=true;
                break;
            }
        }
        if(flag) break;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<wheel[i].wedgeNum;j++)
            {
                wheel[i].angle[j]=(wheel[i].angle[j]+wheel[i].speed)%360;
                wheel[i].length[j]=(wheel[i].length[j]+wheel[i].speed)%360;
            }
        }
    }
    if(time==360) fprintf(fout,"none\n");
    else fprintf(fout,"%d\n",time);
    return 0;
}

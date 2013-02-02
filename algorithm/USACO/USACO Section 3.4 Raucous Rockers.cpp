/*
ID: cyberzh1
LANG: C++
TASK: rockers
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("rockers.in","r");
FILE* fout=fopen("rockers.out","w");
int main()
{
    int n,t,m,len[20];
    fscanf(fin,"%d%d%d",&n,&t,&m);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&len[i]);
    }
    int maxCase=(1<<n),maxSong=0;
    bool include[20];
    for(int i=1;i<maxCase;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) include[j]=true;
            else include[j]=false;
        }
        int current=0,cdNum=1,songNum=0;
        for(int j=0;j<n;j++)
        {
            if(include[j])
            {
                if(current+len[j]<=t)
                {
                    current+=len[j];
                    songNum++;
                }
                else
                {
                    if(++cdNum>m)
                    {
                        break;
                    }
                    current=0;
                    if(len[j]<=t)
                    {
                        current=len[j];
                        songNum++;
                    }
                }
            }
        }
        if(songNum>maxSong)
        {
            maxSong=songNum;
        }
    }
    fprintf(fout,"%d\n",maxSong);
	return 0;
}

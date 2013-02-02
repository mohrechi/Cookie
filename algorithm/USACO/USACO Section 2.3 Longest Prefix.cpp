/*
ID: cyberzh1
LANG: C++
TASK: prefix
*/
#include<stdio.h>
#include<string.h>
FILE* fin=fopen("prefix.in","r");
FILE* fout=fopen("prefix.out","w");
int main()
{
    char primitive[210][15],sequence[200010]={0},temp[100];
    bool visitable[200010];
    int primitiveNum=0,count=0,len,step,max;
    while(fscanf(fin,"%s",primitive[primitiveNum]),*primitive[primitiveNum++]!='.');
    while(fscanf(fin,"%s",temp)!=EOF)
    {
        strcat(sequence,temp);
    }
    len=strlen(sequence);
    for(int i=1;i<len;i++)
    {
        visitable[i]=false;
    }
    visitable[0]=true;
    for(int i=0;i<len;i++)
    {
        if(visitable[i])
        {
            for(int j=0;j<primitiveNum;j++)
            {
                step=strlen(primitive[j]);
                if(not strncmp(primitive[j],sequence+i,step))
                {
                    step+=i;
                    if(step>count)
                    {
                        count=step;
                    }
                    visitable[step]=true;
                }
            }
        }
    }
    fprintf(fout,"%d\n",count);
    return 0;
}

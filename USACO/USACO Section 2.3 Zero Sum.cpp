/*
ID: cyberzh1
LANG: C++
TASK: zerosum
*/
#include<stdio.h>
FILE* fin=fopen("zerosum.in","r");
FILE* fout=fopen("zerosum.out","w");
int numStack[15],numTop,operatStack[15],operatTop,record[15]={0},n;
bool isZero()
{
    for(int i=0;i<operatTop;i++)
    {
        if(operatStack[i]==1)
        {
            numStack[i+1]+=numStack[i];
        }
        else
        {
            numStack[i+1]=numStack[i]-numStack[i+1];
        }
    }
    return not numStack[operatTop];
}
void initStack()
{
    numTop=0,numStack[0]=1;
    operatTop=0;
    for(int i=1;i<n;i++)
    {
        if(not record[i-1])
        {
            numStack[numTop]=numStack[numTop]*10+i+1;
        }
        else
        {
            numStack[++numTop]=i+1;
            operatStack[operatTop++]=record[i-1];
        }
    }
    numTop++;
}
void output()
{
    printf("1");
    fprintf(fout,"1");
    char ch;
    for(int i=0;i<n-1;i++)
    {
        switch (record[i])
        {
            case 0: ch=' ';break;
            case 1: ch='+';break;
            case 2: ch='-';break;
        }
        printf("%c%d",ch,i+2);
        fprintf(fout,"%c%d",ch,i+2);
    }
    printf("\n");
    fprintf(fout,"\n");
}
int main()
{
    fscanf(fin,"%d",&n);
    while(true)
    {
        record[n-2]++;
        for(int i=n-2;i>0;i--)
        {
            if(record[i]==3)
            {
                record[i]=0;
                record[i-1]++;
            }
        }
        initStack();
        if(isZero())
        {
            output();
        }
        if(record[0]==3)
        {
            break;
        }
    }
    return 0;
}

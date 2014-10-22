/*
ID: cyberzh1
LANG: C++
TASK: msquare
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("msquare.in","r");
FILE* fout=fopen("msquare.out","w");
int target[8],resultNum,square[8],temp[8],operation[50000],queue[50000],father[50000],rear,front,t;
char result[100];
bool record[8][8][8][8][8][8][8];
void swap(int &a, int &b)
{
    a^=b,b^=a,a^=b;
}
void copy()
{
    for(int i=0;i<8;i++)
    {
        temp[i]=square[i];
    }
}
bool setRecord(int array[])
{
    if(record[array[0]][array[1]][array[2]][array[3]][array[4]][array[5]][array[6]])
    {
        return false;
    }
    return record[array[0]][array[1]][array[2]][array[3]][array[4]][array[5]][array[6]]=true;
}
int getAddress(int array[])
{
    return array[0]+array[1]*8+array[2]*64+array[3]*512+array[4]*4096+array[5]*32768+array[6]*262144;
}
void getSquare(int num)
{
    bool show[8]={0};
    for(int i=0;i<7;i++)
    {
        t=num%8,num/=8;
        square[i]=t;
        show[t]=true;
    }
    for(int i=0;i<8;i++)
    {
        if(not show[i])
        {
            square[7]=i;
            return;
        }
    }
}
void operate(int command, int array[])
{
    if(command==1)
    {
        swap(array[0],array[4]),swap(array[1],array[5]);
        swap(array[2],array[6]),swap(array[3],array[7]);
    }
    else if(command==2)
    {
        swap(array[0],array[1]),swap(array[4],array[5]);
        swap(array[2],array[3]),swap(array[6],array[7]);
        swap(array[0],array[2]),swap(array[4],array[6]);
    }
    else if(command==3)
    {
        swap(array[1],array[2]),swap(array[5],array[6]);
        swap(array[1],array[6]);
    }
}
void init()
{
    resultNum=0;
    square[0]=0,square[1]=1;
    square[2]=2,square[3]=3;
    square[4]=7,square[5]=6;
    square[6]=5,square[7]=4;
    swap(target[4],target[7]),swap(target[5],target[6]);
}
bool check()
{
    for(int i=0;i<8;i++)
    {
        if(temp[i]!=target[i])
        {
            return false;
        }
    }
    return true;
}
void getResult(int num)
{
    while(num!=-1)
    {
        switch (operation[num])
        {
            case 1: result[resultNum++]='A'; break;
            case 2: result[resultNum++]='B'; break;
            case 3: result[resultNum++]='C'; break;
        }
        num=father[num];
    }
}
void BFS()
{
    rear=0,front=1;
    queue[0]=getAddress(square);
    father[0]=-1,operation[0]=0;
    setRecord(square);
    while(rear<front)
    {
        getSquare(queue[rear]);
        for(int i=1;i<=3;i++)
        {
            copy();
            operate(i,temp);
            if(setRecord(temp))
            {
                queue[front]=getAddress(temp);
                father[front]=rear;
                operation[front]=i;
                if(check())
                {
                    getResult(front);
                    return;
                }
                front++;
            }
        }
        rear++;
    }
}
void output()
{
    fprintf(fout,"%d\n",resultNum);
    while(resultNum--)
    {
        fprintf(fout,"%c",result[resultNum]);
    }
    fprintf(fout,"\n");
}
int main()
{
    for(int i=0;i<8;i++)
    {
        fscanf(fin,"%d",&target[i]);
        target[i]--;
    }
    init();
    BFS();
    output();
    return 0;
}

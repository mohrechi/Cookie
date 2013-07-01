/*
ID: cyberzh1
LANG: C++
TASK: contact
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* fin=fopen("contact.in","r");
FILE* fout=fopen("contact.out","w");
struct Appear
{
    int number,times,len;
    void output()
    {
        for(int i=len-1;i>=0;i--)
        {
            fprintf(fout,"%d",(number&(1<<i))>0?1:0);
        }
    }
}appear[17000];
int cmp(const void* a, const void* b)
{
    if((*(Appear*)a).times==(*(Appear*)b).times)
    {
        return (*(Appear*)a).number-(*(Appear*)b).number;
    }
    return (*(Appear*)b).times-(*(Appear*)a).times;
}
void calc(char s[], int len)
{
    int current=1,i=0;
    while(i<len)
    {
        current<<=1;
        current+=s[i++]-'0';
        appear[current].times++;
    }
}
int main()
{
    int a,b,n,length;
    fscanf(fin,"%d%d%d",&a,&b,&n);
    length=a,b++;
    for(int i=(1<<a);i<=(1<<b);i++)
    {
        if(i>=(1<<length))
        {
            length++;
        }
        appear[i].number=i;
        appear[i].len=length-1;
    }
    for(int i=0;i<17000;i++)
    {
        appear[i].times=0;
    }
    char input[100]="",temp[100];
    while(fscanf(fin,"%s",temp)!=EOF)
    {
        strcat(input,temp);
        int len=strlen(input),i=0;
        while(i<len-b)
        {
            calc(input+i,b);
            i++;
        }
        if(len<=b) continue;
        for(int i=0;i<b;i++)
        {
            input[i]=input[len-b+i];
        }
        input[b]=0;
    }
    int len=strlen(input);
    for(int i=0;i<len;i++)
    {
        calc(input+i,len-i);
    }
    qsort(appear+(1<<a),(1<<b)-(1<<a),sizeof(*appear),cmp);
    int current=appear[1<<a].times;
    int front=(1<<a),rear=(1<<a);
    while(n--)
    {
        while(appear[++front].times==current)
        {
            if(appear[front].times==0 or front>(1<<b))
            {
                return 0;
            }
        }
        if(front>(1<<b))
        {
            return 0;
        }
        current=appear[front].times;
        fprintf(fout,"%d\n",appear[rear].times);
        int count=0;
        while(rear<front)
        {
            if(count%6) fprintf(fout," ");
            appear[rear].output();
            count++,rear++;
            if(count%6==0 or rear==front)
            {
                fprintf(fout,"\n");
            }
        }
    }
    return 0;
}

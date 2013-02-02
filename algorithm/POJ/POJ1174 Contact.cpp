#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Appear
{
    int number,times,len;
    void output()
    {
        printf(" ");
        for(int i=len-1;i>=0;i--)
        {
            printf("%d",(number&(1<<i))>0?1:0);
        }
    }
}appear[17000];
int cmp(const void* a, const void* b)
{
    if((*(Appear*)a).times==(*(Appear*)b).times)
    {
        return (*(Appear*)b).number-(*(Appear*)a).number;
    }
    return (*(Appear*)b).times-(*(Appear*)a).times;
}
void calc(char s[], int len)
{
    int current=1,i=0;
    while(i<len)
    {
        current<<=1;
        current+=s[i++];
        appear[current].times++;
    }
}
int main()
{
    int a,b,n,length;
    scanf("%d%d%d",&a,&b,&n);
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
    char input[2010000];
    int len=0;
    while(true)
    {
        char ch=getchar();
        if(ch=='0') input[len++]=0;
        else if(ch=='1') input[len++]=1;
        else if(ch=='2') break;
    }
    input[len]=2;
    int i=0;
    while(i<len-b)
    {
        calc(input+i,b);
        i++;
    }
    if(len>b)
    {
        for(i=0;i<b;i++)
        {
            input[i]=input[len-b+i];
        }
        input[b]=0;
    }
    len=b;
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
        printf("%d",appear[rear].times);
        int count=0;
        while(rear<front)
        {
            appear[rear++].output();
        }
        printf("\n");
    }
    return 0;
}

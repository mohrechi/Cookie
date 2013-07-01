#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

struct Count
{
    char ch1,ch2;
    int num;
}count[70000];
int n, total;
char input[100],*p, last;

int cmp(const void* a, const void* b)
{
    if((*(Count*)b).num==(*(Count*)a).num)
    {
        return (*(Count*)a).ch1-(*(Count*)b).ch1;
    }
    return (*(Count*)b).num-(*(Count*)a).num;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        getchar();
        for(int i=0;i<128;i++)
        {
            for(int j=0;j<128;j++)
            {
                count[i*128+j].ch1=i;
                count[i*128+j].ch2=j;
                count[i*128+j].num=0;
            }
        }
        total=0, last=0;
        for(int i=0;i<n;i++)
        {
            gets(input);
            int len=strlen(input);
            if(i)
            {
                count[last*128+input[0]].num++;
            }
            total+=len;
            len--;
            for(int j=0;j<len;j++)
            {
                count[input[j]*128+input[j+1]].num++;
            }
            last=input[len];
        }
        total--;
        qsort(count,65535,sizeof(*count),cmp);
        for(int i=0;i<5;i++)
        {
            printf("%c%c %d %.6lf\n",count[i].ch1,count[i].ch2,count[i].num,(double)count[i].num/total);
        }
        printf("\n");
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    int score,index,num;
    char time[100];
}stu[105];

int cmpByTime(const void* a, const void* b)
{
    if((*(Student*)a).num==(*(Student*)b).num) return strcmp((*(Student*)a).time, (*(Student*)b).time);
    return (*(Student*)b).num-(*(Student*)a).num;
}

int cmpByIndex(const void* a, const void* b)
{
    return (*(Student*)a).index-(*(Student*)b).index;
}

int main()
{
    int n,num[6];
    while(scanf("%d",&n),n+1)
    {
        for(int i=1;i<6;i++) num[i]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%s",&stu[i].num,stu[i].time);
            stu[i].score=stu[i].num*10+50;
            stu[i].index=i;
            ++num[stu[i].num];
        }
        for(int i=1;i<6;i++) num[i]/=2;
        qsort(stu,n,sizeof(*stu),cmpByTime);
        int j=0;
        for(int i=5;i>0;--i)
        {
            for(int k=0;stu[j].num==i;++j,++k)
            {
                if(k<num[i] && i<5) stu[j].score+=5;
            }
        }
        qsort(stu,n,sizeof(*stu),cmpByIndex);
        for(int i=0;i<n;i++)
        {
            printf("%d\n",stu[i].score);
        }
        printf("\n");
    }
    return 0;
}

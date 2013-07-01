#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student
{
    char name[30];
    int score;
}stu[1005];
int cmp(const void* a, const void* b)
{
    if((*(Student*)b).score==(*(Student*)a).score)
    {
        return strcmp((*(Student*)a).name,(*(Student*)b).name);
    }
    return (*(Student*)b).score-(*(Student*)a).score;
}
int main()
{
    int n,m,g,equ[15],num,t;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&m,&g);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&equ[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",stu[i].name,&num);
            stu[i].score=0;
            while(num--)
            {
                scanf("%d",&t);
                stu[i].score+=equ[t];
            }
        }
        qsort(stu,n,sizeof(*stu),cmp);
        num=n;
        for(int i=0;i<n;i++)
        {
            if(stu[i].score<g)
            {
                num=i;
                break;
            }
        }
        printf("%d\n",num);
        for(int i=0;i<num;i++)
        {
            printf("%s %d\n",stu[i].name, stu[i].score);
        }
    }
    return 0;
}

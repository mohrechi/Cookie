#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Person
{
    char name[20];
    int num,time;
}person[1000];

int cmp(const void* a, const void* b)
{
    if((*(Person*)a).num==(*(Person*)b).num)
    {
        if((*(Person*)a).time==(*(Person*)b).time)
        {
            return strcmp((*(Person*)a).name,(*(Person*)b).name);
        }
        return (*(Person*)a).time-(*(Person*)b).time;
    }
    return (*(Person*)b).num-(*(Person*)a).num;
}

int main()
{
    int n,m,pnum=0,t,w;
    char score[20];
    scanf("%d%d",&n,&m);
    while(scanf("%s",person[pnum].name)!=EOF)
    {
        person[pnum].num=0;
        person[pnum].time=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",score);
            if(*score=='-' || *score=='0') continue;
            t=0,w=0;
            int j;
            for(j=0;score[j];j++)
            {
                if(score[j]=='(') break;
                t=t*10+score[j]-'0';
            }
            if(score[j++])
            {
                for(;score[j]!=')';++j)
                {
                    w=w*10+score[j]-'0';
                }
            }
            person[pnum].num++;
            person[pnum].time+=t+w*m;
        }
        ++pnum;
    }
    qsort(person,pnum,sizeof(*person),cmp);
    for(int i=0;i<pnum;++i)
    {
        printf("%-10s %2d %4d\n",person[i].name,person[i].num,person[i].time);
    }
    return 0;
}

/*
ID: cyberzh1
LANG: C++
TASK: picture
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
FILE* fin=fopen("picture.in","r");
FILE* fout=fopen("picture.out","w");
struct Segment
{
    int u,v,l;
    bool add;
}seg1[10000],seg2[10000];
int n,answer,level[20005];
int cmp(const void* a, const void* b)
{
    if((*(Segment*)a).l==(*(Segment*)b).l)
    {
        return (*(Segment*)b).add-(*(Segment*)a).add;
    }
    return (*(Segment*)a).l-(*(Segment*)b).l;
}
void find(Segment seg[10000])
{
    memset(level,0,sizeof(level));
    for(int i=0;i<n;i++)
    {
        if(seg[i].add)
        {
            for(int j=seg[i].u;j<seg[i].v;j++)
            {
                if(level[j]==0)
                {
                    answer++;
                }
                level[j]++;
            }
        }
        else
        {
            for(int j=seg[i].u;j<seg[i].v;j++)
            {
                if(level[j]==1)
                {
                    answer++;
                }
                level[j]--;
            }
        }
    }
}
int main()
{
    fscanf(fin,"%d",&n);
    int a,b,c,d;
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d%d%d%d",&a,&b,&c,&d);
        a+=10000,b+=10000,c+=10000,d+=10000;
        seg1[i].l=b,seg1[i].u=a,seg1[i].v=c,seg1[i].add=true;
        seg2[i].l=a,seg2[i].u=b,seg2[i].v=d,seg2[i].add=true;
        seg1[i+n].l=d,seg1[i+n].u=a,seg1[i+n].v=c,seg1[i+n].add=false;
        seg2[i+n].l=c,seg2[i+n].u=b,seg2[i+n].v=d,seg2[i+n].add=false;
    }
    n*=2;
    qsort(seg1,n,sizeof(*seg1),cmp);
    qsort(seg2,n,sizeof(*seg2),cmp);
    find(seg1);
    find(seg2);
    fprintf(fout,"%d\n",answer);
    return 0;
}

/*
ID: cyberzh1
LANG: C++
TASK: rect1
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("rect1.in","r");
FILE* fout=fopen("rect1.out","w");
int rectNum,area[1000],stackTop;
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a<b?a:b;
}
struct Rect
{
    int llx,lly,urx,ury,color;
    Rect(){}
    Rect(int x1, int y1, int x2, int y2, int c)
    {
        llx=x1,lly=y1,urx=x2,ury=y2,color=c;
    }
}rect[1000];
int main()
{
    fscanf(fin,"%d%d%d",&rect[0].urx,&rect[0].ury,&rectNum);
    rect[0].llx=0,rect[0].lly=0,rect[0].color=1;
    for(int i=1;i<=rectNum;i++)
    {
        fscanf(fin,"%d%d%d%d%d",&rect[i].llx,&rect[i].lly,&rect[i].urx,&rect[i].ury,&rect[i].color);
    }
    Rect queue[10005];
    int front=1,rear=0,current;
    queue[0]=rect[0];
    for(int i=1;i<=rectNum;i++)
    {
        current=front;
        while(rear!=current)
        {
            if(rect[i].urx<queue[rear].llx or rect[i].llx>queue[rear].urx or rect[i].ury<queue[rear].lly or rect[i].lly>queue[rear].ury)
            {
                queue[front]=queue[rear];
                if(++front>10000) front=0;
                if(++rear>10000) rear=0;
                continue;
            }
            if(rect[i].llx<=queue[rear].llx and rect[i].urx>=queue[rear].urx and rect[i].lly<=queue[rear].lly and rect[i].ury>=queue[rear].ury)
            {
                if(++rear>10000) rear=0;
                continue;
            }
            if(rect[i].llx>queue[rear].llx)
            {
                queue[front]=queue[rear],queue[front].urx=rect[i].llx;
                if(++front>10000) front=0;
                queue[rear].llx=rect[i].llx;
            }
            if(rect[i].urx<queue[rear].urx)
            {
                queue[front]=queue[rear],queue[front].llx=rect[i].urx;
                if(++front>10000) front=0;
                queue[rear].urx=rect[i].urx;
            }
            if(rect[i].lly>queue[rear].lly)
            {
                queue[front]=queue[rear],queue[front].ury=rect[i].lly;
                if(++front>10000) front=0;
                queue[rear].lly=rect[i].lly;
            }
            if(rect[i].ury<queue[rear].ury)
            {
                queue[front]=queue[rear],queue[front].lly=rect[i].ury;
                if(++front>10000) front=0;
                queue[rear].ury=rect[i].ury;
            }
            if(++rear>10000) rear=0;
        }
        queue[front]=rect[i];
        if(++front>10000) front=0;
    }
    for(int i=1;i<=2500;i++) area[i]=0;
    while(rear!=front)
    {
        area[queue[rear].color]+=(queue[rear].urx-queue[rear].llx)*(queue[rear].ury-queue[rear].lly);
        if(++rear>10000) rear=0;
    }
    for(int i=1;i<=2500;i++)
    {
        if(area[i]>0)
        {
            fprintf(fout,"%d %d\n",i,area[i]);
        }
    }
    return 0;
}

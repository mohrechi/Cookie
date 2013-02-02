/*
ID: cyberzh1
LANG: C++
TASK: packrec
*/
#include<stdio.h>
#include<stdlib.h>
struct Rect
{
    int width,height;
}r[4],rect[4];
struct Answer
{
    int area,width,height;
}ans[100];
int num,minArea;
int cmp(const void* a, const void* b)
{
    return (*(Answer*)a).width-(*(Answer*)b).width;
}
int max(int a, int b)
{
    return a>b?a:b;
}
int min(int a, int b)
{
    return a<b?a:b;
}
int swap(int &a, int &b)
{
    a^=b,b^=a,a^=b;
}
void addAnswer(int width, int height)
{
    int area=width*height;
    if(area<=minArea)
    {
        minArea=area;
        if(width>height)
        {
            swap(width,height);
        }
        int i=0;
        while(i<num)
        {
            if(area==ans[i].area and width==ans[i].width and height==ans[i].height)
            {
                return;
            }
            i++;
        }
        ans[num].area=area;
        ans[num].width=width, ans[num].height=height;
        num++;
    }
}
void Solve1()
{
    int width=0,height=0;
    for(int i=0;i<4;i++)
    {
        width+=rect[i].width;
        height=max(height,rect[i].height);
    }
    addAnswer(width,height);
}
void Solve2()
{
    int width,height;
    for(int i=0;i<4;i++)
    {
        int temp1=0,temp2=0;
        for(int j=0;j<4;j++)
        {
            if(i!=j)
            {
                temp1+=rect[j].width;
                temp2=max(temp2,rect[j].height);
            }
        }
        width=max(temp1,rect[i].height);
        height=temp2+rect[i].width;
        addAnswer(width,height);
    }
}
void Solve3()
{
    int width, height;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==j) continue;
            int temp1=0, temp2=0;
            int temp3=0, temp4=0;
            Rect temp[4];
            int t=0;
            for(int k=0;k<4;k++)
            {
                if(k!=i and k!=j)
                {
                    temp1+=rect[k].width;
                    temp2=max(temp2,rect[k].height);
                    temp3+=rect[k].height;
                    temp4=max(temp4,rect[k].width);
                    temp[t].width=rect[k].width,temp[t++].height=rect[k].height;
                }
            }
            width=max(temp1,rect[j].height)+rect[i].width;
            height=max(temp2+rect[j].width, rect[i].height);
            addAnswer(width,height);
            width=rect[i].width+rect[j].width+temp4;
            height=max(max(rect[i].height,rect[j].height),temp3);
            addAnswer(width,height);
            width=rect[i].width+rect[j].width;
            if(temp1<=width)
            {
                if(temp[0].height<temp[1].height)
                {
                    swap(temp[0].width,temp[1].width);
                    swap(temp[0].height,temp[1].height);
                }
                temp[2].width=rect[i].width, temp[2].height=rect[i].height;
                temp[3].width=rect[j].width, temp[3].height=rect[j].height;
                if(temp[2].height>temp[3].height)
                {
                    swap(temp[2].width,temp[3].width);
                    swap(temp[2].height,temp[3].height);
                }
                if(temp[0].width<=temp[2].width)
                {
                    height=max(temp[0].height+temp[2].height,temp[1].height+temp[3].height);
                    addAnswer(width,height);
                }
            }
        }
    }
}
void Solve()
{
    for(int i=0;i<=15;i++)
    {
        for(int j=0;j<4;j++)
        {
            rect[j].width=r[j].width;
            rect[j].height=r[j].height;
        }
        for(int j=0;j<4;j++)
        {
            if(i&(1<<j))
            {
                swap(rect[j].width,rect[j].height);
            }
        }
        Solve1(), Solve2(), Solve3();
    }
}
int main()
{
    FILE* fin=fopen("packrec.in","r");
    FILE* fout=fopen("packrec.out","w");
    num=0;
    for(int i=0;i<4;i++)
    {
        fscanf(fin,"%d%d",&r[i].width,&r[i].height);
    }
    minArea=0x7FFFFFFF;
    Solve();
    qsort(ans,num,sizeof(*ans),cmp);
    fprintf(fout,"%d\n",minArea);
    for(int i=0;i<num;i++)
    {
        if(ans[i].area==minArea)
        {
            fprintf(fout,"%d %d\n",ans[i].width, ans[i].height);
        }
    }
    return 0;
}

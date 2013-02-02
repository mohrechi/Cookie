/*
ID: cyberzh1
LANG: C++
TASK: window
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("window.in","r");
FILE* fout=fopen("window.out","w");
void swap(int &a, int &b)
{
    a^=b,b^=a,a^=b;
}
struct Window
{
    char name;
    int x,y,X,Y;
    void input()
    {
        fscanf(fin,"(%c,%d,%d,%d,%d)\n",&name,&x,&y,&X,&Y);
        if(x>X) swap(x,X);
        if(y>Y) swap(y,Y);
    }
}window[100];
struct Rect
{
    int x,y,X,Y;
    int getArea()
    {
        return (X-x)*(Y-y);
    }
}rect[10000];
int windowNum;
char windowPosition[100];
void createWindow()
{
    window[windowNum].input();
    windowPosition[windowNum]=window[windowNum].name;
    windowNum++;
}
int findWindow(char name)
{
    for(int i=0;i<windowNum;i++)
    {
        if(windowPosition[i]==name)
        {
            return i;
        }
    }
    return -1;
}
int locateWindow(char name)
{
    for(int i=0;i<windowNum;i++)
    {
        if(window[i].name==name)
        {
            return i;
        }
    }
    return -1;
}
void topWindow()
{
    char name;
    fscanf(fin,"(%c)\n",&name);
    int index=findWindow(name);
    for(int i=index;i<windowNum;i++)
    {
        windowPosition[i]=windowPosition[i+1];
    }
    windowPosition[windowNum-1]=name;
}
void bottomWindow()
{
    char name;
    fscanf(fin,"(%c)\n",&name);
    int index=findWindow(name);
    for(int i=index;i>0;i--)
    {
        windowPosition[i]=windowPosition[i-1];
    }
    windowPosition[0]=name;
}
void destroyWindow()
{
    char name;
    fscanf(fin,"(%c)\n",&name);
    int index=findWindow(name);
    for(int i=index;i<windowNum;i++)
    {
        windowPosition[i]=windowPosition[i+1];
    }
    index=locateWindow(name);
    window[index]=window[windowNum-1];
    windowNum--;
}
void calcWindow()
{
    char name;
    fscanf(fin,"(%c)\n",&name);
    int position=findWindow(name);
    int index=locateWindow(name);
    int rear=0, front=1;
    rect[0].x=window[index].x, rect[0].y=window[index].y;
    rect[0].X=window[index].X, rect[0].Y=window[index].Y;
    for(int i=position+1;i<windowNum;i++)
    {
        index=locateWindow(windowPosition[i]);
        int temp=front;
        for(int j=rear;j<temp;j++)
        {
            if(window[index].X<=rect[j].x or window[index].x>=rect[j].X or window[index].Y<=rect[j].y or window[index].y>=rect[j].Y)
            {
                rect[front++]=rect[j];
                continue;
            }
            if(window[index].x>rect[j].x)
            {
                rect[front]=rect[j];
                rect[front++].X=window[index].x;
                rect[j].x=window[index].x;
            }
            if(window[index].X<rect[j].X)
            {
                rect[front]=rect[j];
                rect[front++].x=window[index].X;
                rect[j].X=window[index].X;
            }
            if(window[index].y>rect[j].y)
            {
                rect[front]=rect[j];
                rect[front++].Y=window[index].y;
                rect[j].y=window[index].y;
            }
            if(window[index].Y<rect[j].Y)
            {
                rect[front]=rect[j];
                rect[front++].y=window[index].Y;
                rect[j].Y=window[index].Y;
            }
        }
        rear=temp;
    }
    int seenArea=0;
    for(int i=rear;i<front;i++)
    {
        seenArea+=rect[i].getArea();
    }
    index=locateWindow(name);
    rect[0].x=window[index].x, rect[0].y=window[index].y;
    rect[0].X=window[index].X, rect[0].Y=window[index].Y;
    fprintf(fout,"%.3lf\n",100.0*seenArea/rect[0].getArea());
}
int main()
{
    char ch;
    while(fscanf(fin,"%c",&ch)!=EOF)
    {
        switch (ch)
        {
            case 'w': createWindow(); break;
            case 't': topWindow(); break;
            case 'b': bottomWindow(); break;
            case 'd': destroyWindow(); break;
            case 's': calcWindow(); break;
        }
    }
	return 0;
}

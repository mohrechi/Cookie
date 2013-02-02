/*
ID: cyberzh1
LANG: C++
TASK: fence3
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("fence3.in","r");
FILE* fout=fopen("fence3.out","w");
void swap(int &x, int &y)
{
    x^=y, y^=x, x^=y;
}
struct Fence
{
    int minx, miny, maxx, maxy;
    void input()
    {
        fscanf(fin,"%d%d%d%d",&minx,&miny,&maxx,&maxy);
        if(minx>maxx)
        {
            swap(minx, maxx);
        }
        if(miny>maxy)
        {
            swap(miny,maxy);
        }
    }
}fence[135];
int fenceNum;
double dist(double x, double y)
{
    double ans=0,xd,yd;
    for(int i=0;i<fenceNum;i++)
    {
        if(fence[i].minx>x)
        {
            xd=fence[i].minx-x;
        }
        else if(fence[i].maxx<x)
        {
            xd=x-fence[i].maxx;
        }
        else
        {
            xd=0;
        }
        if(fence[i].miny>y)
        {
            yd=fence[i].miny-y;
        }
        else if(fence[i].maxy<y)
        {
            yd=y-fence[i].maxy;
        }
        else
        {
            yd=0;
        }
        ans+=sqrt(xd*xd+yd*yd);
    }
    return ans;
}
int main()
{
    fscanf(fin,"%d",&fenceNum);
    for(int i=0;i<fenceNum;i++)
    {
        fence[i].input();
    }
    double startX=0,startY=0, step=5,min=1e10,temp,px,py;
    while(step>1e-3)
    {
        for(int i=0;i<=20;i++)
        {
            for(int j=0;j<=20;j++)
            {
                temp=dist(startX+i*step, startY+j*step);
                if(temp<min)
                {
                    min=temp;
                    px=startX+i*step;
                    py=startY+j*step;
                }
            }
        }
        step/=10;
        startX=px-10*step;
        startY=py-10*step;
    }
    fprintf(fout,"%.1lf %.1lf %.1lf\n",px,py,min);
	return 0;
}

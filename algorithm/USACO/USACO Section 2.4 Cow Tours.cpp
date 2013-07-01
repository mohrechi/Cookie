/*
ID: cyberzh1
LANG: C++
TASK: cowtour
*/
#include<stdio.h>
#include<math.h>
FILE* fin=fopen("cowtour.in","r");
FILE* fout=fopen("cowtour.out","w");
struct Point
{
    double x,y;
}point[200];
double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double graph[200][200],len[200],fieldlen[200];
int n,field[200];
int find(int i)
{
    if(field[i]==i) return i;
    return field[i]=find(field[i]);
}
void Union(int a, int b)
{
    a=find(a),b=find(b);
    field[b]=a;
}
int main()
{
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%lf%lf",&point[i].x,&point[i].y);
    }
    char ch;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ch=fgetc(fin);
            if(ch=='0')
            {
                graph[i][j]=1e5;
            }
            if(ch=='1')
            {
                graph[i][j]=dist(point[i],point[j]);
            }
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(ch=='\n')
            {
                j--;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        field[i]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j and graph[i][j]!=1e5)
            {
                Union(i,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(len[i]<graph[i][j] and graph[i][j]<1e5)
            {
                len[i]=graph[i][j];
            }
        }
        if(len[i]>fieldlen[field[i]])
        {
            fieldlen[field[i]]=len[i];
        }
    }
    double min=1e5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(field[i]==field[j])
            {
                continue;
            }
            double temp=len[i]+len[j]+dist(point[i],point[j]);
            if(temp<fieldlen[field[i]])
            {
                temp=fieldlen[field[i]];
            }
            if(temp<fieldlen[field[j]])
            {
                temp=fieldlen[field[j]];
            }
            if(temp<min)
            {
                min=temp;
            }
        }
    }
    fprintf(fout,"%.6lf\n",min);
    return 0;
}

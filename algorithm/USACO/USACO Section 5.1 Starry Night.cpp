/*
ID: cyberzh1
LANG: C++
TASK: starry
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("starry.in","r");
FILE* fout=fopen("starry.out","w");
struct Cluster
{
    char startX, startY, endX, endY, width, height;
    char map[105][105];
    char belong;
    short starNum;
}cluster[505], tempCluster, originCluster;
int W,H,clusterNum;
char skyMap[105][105],result[105][105],tempMap[105][105];
bool visited[105][105];
void input()
{
    fscanf(fin,"%d%d",&W,&H);
    for(int i=0;i<H;i++)
    {
        fscanf(fin,"%s",skyMap[i]);
    }
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            skyMap[i][j]-='0';
        }
    }
}
void give(int i,int j)
{
    if(i<0 or i>=H or j<0 or j>=W)
    {
        return;
    }
    if(not visited[i][j] and skyMap[i][j])
    {
        visited[i][j]=true;
        if(i<cluster[clusterNum].startX)
        {
            cluster[clusterNum].startX=i;
        }
        if(j<cluster[clusterNum].startY)
        {
            cluster[clusterNum].startY=j;
        }
        if(i>cluster[clusterNum].endX)
        {
            cluster[clusterNum].endX=i;
        }
        if(j>cluster[clusterNum].endY)
        {
            cluster[clusterNum].endY=j;
        }
        cluster[clusterNum].map[i][j]=1;
        cluster[clusterNum].starNum++;
        give(i-1,j-1), give(i+1,j+1);
        give(i-1,j+1), give(i+1,j-1);
        give(i,j-1), give(i+1,j);
        give(i,j+1), give(i-1,j);
    }
}
void find()
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(not visited[i][j] and skyMap[i][j])
            {
                cluster[clusterNum].startX=i;
                cluster[clusterNum].startY=j;
                cluster[clusterNum].endX=i;
                cluster[clusterNum].endY=j;
                give(i,j);
                cluster[clusterNum].width=cluster[clusterNum].endY-cluster[clusterNum].startY+1;
                cluster[clusterNum].height=cluster[clusterNum].endX-cluster[clusterNum].startX+1;
                clusterNum++;
            }
        }
    }
}
void copy(int origin, int sample)
{
    for(int i=cluster[origin].startX;i<=cluster[origin].endX;i++)
    {
        for(int j=cluster[origin].startY;j<=cluster[origin].endY;j++)
        {
            originCluster.map[i-cluster[origin].startX][j-cluster[origin].startY]=cluster[origin].map[i][j];
        }
    }
    originCluster.width=cluster[origin].width;
    originCluster.height=cluster[origin].height;
    for(int i=cluster[sample].startX;i<=cluster[sample].endX;i++)
    {
        for(int j=cluster[sample].startY;j<=cluster[sample].endY;j++)
        {
            tempCluster.map[i-cluster[sample].startX][j-cluster[sample].startY]=cluster[sample].map[i][j];
        }
    }
    tempCluster.width=cluster[sample].width;
    tempCluster.height=cluster[sample].height;
}
bool same()
{
    if(originCluster.width!=tempCluster.width)
    {
        return false;
    }
    if(originCluster.height!=tempCluster.height)
    {
        return false;
    }
    for(int i=0;i<originCluster.height;i++)
    {
        for(int j=0;j<originCluster.width;j++)
        {
            if(originCluster.map[i][j]!=tempCluster.map[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void rotate()
{
    for(int i=0;i<tempCluster.height;i++)
    {
        for(int j=0;j<tempCluster.width;j++)
        {
            tempMap[j][tempCluster.height-i-1]=tempCluster.map[i][j];
        }
    }
    char temp;
    temp=tempCluster.width;
    tempCluster.width=tempCluster.height;
    tempCluster.height=temp;
    for(int i=0;i<tempCluster.height;i++)
    {
        for(int j=0;j<tempCluster.width;j++)
        {
            tempCluster.map[i][j]=tempMap[i][j];
        }
    }
}
void mirror()
{
    for(int i=0;i<tempCluster.height;i++)
    {
        for(int j=0;j<tempCluster.width;j++)
        {
            tempMap[i][tempCluster.width-j-1]=tempCluster.map[i][j];
        }
    }
    for(int i=0;i<tempCluster.height;i++)
    {
        for(int j=0;j<tempCluster.width;j++)
        {
            tempCluster.map[i][j]=tempMap[i][j];
        }
    }
}
bool compare(int origin, int sample)
{
    if(cluster[origin].starNum!=cluster[sample].starNum)
    {
        return false;
    }
    copy(origin, sample);
    for(int i=0;i<4;i++)
    {
        if(same())
        {
            return true;
        }
        rotate();
    }
    mirror();
    for(int i=0;i<4;i++)
    {
        if(same())
        {
            return true;
        }
        rotate();
    }
    return false;
}
void sort()
{
    char count='a';
    for(int i=0;i<clusterNum;i++)
    {
        int j;
        for(j=0;j<i;j++)
        {
            if(compare(j,i))
            {
                cluster[i].belong=cluster[j].belong;
                break;
            }
        }
        if(j==i)
        {
            cluster[i].belong=count++;
        }
    }
}
void make()
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            result[i][j]='0';
        }
    }
    for(int k=0;k<clusterNum;k++)
    {
        for(int i=cluster[k].startX;i<=cluster[k].endX;i++)
        {
            for(int j=cluster[k].startY;j<=cluster[k].endY;j++)
            {
                if(cluster[k].map[i][j])
                {
                    result[i][j]=cluster[k].belong;
                }
            }
        }
    }
}
void output()
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            fprintf(fout,"%c",result[i][j]);
        }
        fprintf(fout,"\n");
    }
}
int main()
{
    input();
    find();
    sort();
    make();
    output();
    return 0;
}

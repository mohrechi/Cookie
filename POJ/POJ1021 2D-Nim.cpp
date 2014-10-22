#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

struct set
{
    int num, width, height;
    bool graph[100][100];
    void rotate()
    {
        bool temp[100][100];
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                temp[width-j-1][i]=graph[i][j];
            }
        }
        width^=height;
        height^=width;
        width^=height;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                graph[i][j]=temp[i][j];
            }
        }
    }
    void mirror()
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<(width>>1);j++)
            {
                bool temp=graph[i][j];
                graph[i][j]=graph[i][width-j-1];
                graph[i][width-j-1]=temp;
            }
        }
    }
    bool compareGraph(set other)
    {
        if(width!=other.width) return false;
        if(height!=other.height) return false;
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                if(graph[i][j]!=other.graph[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool equal(set other)
    {
        if(num!=other.num)
        {
            return false;
        }
        for(int i=0;i<4;i++)
        {
            if(compareGraph(other)) return true;
            rotate();
        }
        mirror();
        for(int i=0;i<4;i++)
        {
            if(compareGraph(other)) return true;
            rotate();
        }
        return false;
    }
    void print()
    {
        printf("%d %d %d: \n",width,height,num);
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                printf("%d",graph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}leftSet[5000], rightSet[5000];

int n,m,pointNum,leftNum,rightNum;
bool graph[105][105],give[105][105],used[5000];

void printGraph()
{
    printf("Graph: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printGive()
{
    printf("Give: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d",give[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addTo(set singleSet[], int &num, int left, int right, int up, int bottom)
{
    singleSet[num].num=0;
    singleSet[num].width=right-left+1;
    singleSet[num].height=bottom-up+1;
    for(int i=up;i<=bottom;i++)
    {
        for(int j=left;j<=right;j++)
        {
            singleSet[num].graph[i-up][j-left]=give[i][j];
            if(give[i][j])
            {
                singleSet[num].num++;
                graph[i][j]=false;
                give[i][j]=false;
            }
        }
    }
    num++;
}

void findGive(int x, int y, int &left, int &right, int &up, int &bottom)
{
    if(x<0 || y<0 || x>=n || y>=m)
    {
        return;
    }
    if(graph[x][y] && !give[x][y])
    {
        if(x<up) up=x;
        if(x>bottom) bottom=x;
        if(y<left) left=y;
        if(y>right) right=y;
        give[x][y]=true;
        findGive(x-1,y, left,right,up,bottom);
        findGive(x+1,y, left,right,up,bottom);
        findGive(x,y-1, left,right,up,bottom);
        findGive(x,y+1, left,right,up,bottom);
    }
}

void divide(set singleSet[], int &num)
{
    num=0;
    memset(give,false,sizeof(give));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(graph[i][j])
            {
                int left=200, right=0, up=200, bottom=0;
                findGive(i,j,left, right, up, bottom);
                addTo(singleSet, num, left, right ,up, bottom);
            }
        }
    }
}

void getGraph(set singleSet[], int &num)
{
    memset(graph,false,sizeof(graph));
    for(int i=0;i<pointNum;i++)
    {
        int tx, ty;
        scanf("%d%d",&tx,&ty);
        graph[tx][ty]=true;
    }
    divide(singleSet, num);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&pointNum);
        getGraph(leftSet, leftNum);
        getGraph(rightSet, rightNum);
        memset(used,false,sizeof(used));
        if(leftNum==rightNum)
        {
            bool flag=true;
            for(int i=0;i<leftNum;i++)
            {
                int j;
                for(j=0;j<rightNum;j++)
                {
                    if(!used[j])
                    {
                        if(leftSet[i].equal(rightSet[j]))
                        {
                            used[j]=true;
                            break;
                        }
                    }
                }
                if(j==rightNum)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

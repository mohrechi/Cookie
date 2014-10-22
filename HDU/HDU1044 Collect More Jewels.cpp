#include <stdio.h>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int width,height,limit,jewelNumber,value[15];
int step[15][15],maxValue,allValue;
char graph[55][55];
bool visit[55][55][15],nodeVisit[15];
int stepX[]={1,0,-1,0};
int stepY[]={0,1,0,-1};

struct Node
{
    int x,y,step,prev;
}node[15];

void input()
{
    scanf("%d%d%d%d",&width,&height,&limit,&jewelNumber);
    allValue=0;
    for(int i=1;i<=jewelNumber;i++)
    {
        scanf("%d",&value[i]);
        allValue+=value[i];
    }
    value[0]=0;
    value[jewelNumber+1]=0;
    memset(graph, '*', sizeof(graph));
    for(int i=1;i<=height;i++)
    {
        scanf("%s",graph[i]+1);
    }
}

void initNode()
{
    for(int i=1;i<=height;i++)
    {
        for(int j=1;j<=width;j++)
        {
            if(graph[i][j]=='@')
            {
                node[0].x=i;
                node[0].y=j;
                node[0].step=0;
                node[0].prev=0;
            }
            else if(graph[i][j]=='<')
            {
                node[jewelNumber+1].x=i;
                node[jewelNumber+1].y=j;
                node[jewelNumber+1].step=0;
                node[jewelNumber+1].prev=jewelNumber+1;
            }
            else if(graph[i][j]>='A' && graph[i][j]<='Z')
            {
                int temp = graph[i][j]-'A'+1;
                node[temp].x=i;
                node[temp].y=j;
                node[temp].step=0;
                node[temp].prev=temp;
            }
        }
    }
}

bool inside(Node node)
{
    return node.x>0 && node.x<=height && node.y>0 && node.y<=width;
}

bool walkable(Node node)
{
    return node.step<=limit && !visit[node.x][node.y][node.prev] && graph[node.x][node.y]!='*';
}

void printStep()
{
    printf("Step: \n");
    for(int i=0;i<=jewelNumber+1;i++)
    {
        for(int j=0;j<=jewelNumber+1;j++)
        {
            printf("%d\t",step[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void bfs()
{
    queue<Node> q;
    memset(visit,false,sizeof(visit));
    memset(step,-1,sizeof(step));
    q.push(node[0]);
    visit[node[0].x][node[0].y][node[0].prev]=true;
    while(!q.empty())
    {
        Node temp=q.front();
        Node newNode;
        for(int i=0;i<4;i++)
        {
            newNode.x=temp.x+stepX[i];
            newNode.y=temp.y+stepY[i];
            newNode.step=temp.step+1;
            newNode.prev=temp.prev;
            if(inside(newNode) && walkable(newNode))
            {
                visit[newNode.x][newNode.y][newNode.prev]=true;
                q.push(newNode);
                if(graph[newNode.x][newNode.y]=='@')
                {
                    step[newNode.prev][0]=newNode.step;
                    step[0][newNode.prev]=newNode.step;
                    newNode.prev=0;
                    newNode.step=0;
                    visit[newNode.x][newNode.y][newNode.prev]=true;
                    q.push(newNode);
                }
                else if(graph[newNode.x][newNode.y]=='<')
                {
                    step[newNode.prev][jewelNumber+1]=newNode.step;
                    step[jewelNumber+1][newNode.prev]=newNode.step;
                    newNode.prev=jewelNumber+1;
                    newNode.step=0;
                    visit[newNode.x][newNode.y][newNode.prev]=true;
                    q.push(newNode);
                }
                else if(graph[newNode.x][newNode.y]>='A' && graph[newNode.x][newNode.y]<='Z')
                {
                    step[newNode.prev][graph[newNode.x][newNode.y]-'A'+1]=newNode.step;
                    step[graph[newNode.x][newNode.y]-'A'+1][newNode.prev]=newNode.step;
                    newNode.prev=graph[newNode.x][newNode.y]-'A'+1;
                    newNode.step=0;
                    visit[newNode.x][newNode.y][newNode.prev]=true;
                    q.push(newNode);
                }
            }
        }
        q.pop();
    }
    //printStep();
}

void dfs(int index, int currentValue, int stepNumber)
{
    //printf("%d %d %d\n",index, currentValue, stepNumber);
    if(maxValue==allValue || stepNumber>limit)
    {
        return;
    }
    if(index==jewelNumber+1 && stepNumber<=limit && currentValue>maxValue)
    {
        maxValue = currentValue;
    }
    for(int i=1;i<=jewelNumber+1;i++)
    {
        if(!nodeVisit[i] && step[index][i]!=-1)
        {
            nodeVisit[i]=true;
            dfs(i, currentValue+value[i], stepNumber+step[index][i]);
            nodeVisit[i]=false;
        }
    }
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        input();
        initNode();
        bfs();
        maxValue=-1;
        memset(nodeVisit, false, sizeof(nodeVisit));
        dfs(0,0,0);
        if(i>1)
        {
            printf("\n");
        }
        printf("Case %d:\n",i);
        if(maxValue==-1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("The best score is %d.\n",maxValue);
        }
    }
    return 0;
}

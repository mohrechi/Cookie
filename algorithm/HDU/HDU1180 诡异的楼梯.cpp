#include <stdio.h>
#include <memory.h>

const int inf=0x7FFFFFFF;
int m,n,minTime;
char graph[25][25];
int stepX[]={1,0,-1,0};
int stepY[]={0,1,0,-1};
bool visit[25][25];

template<typename T>
class ZsysQueue
{
public:
    ZsysQueue()
    {
        this->rearP=0;
        this->frontP=0;
    }

    T front()
    {
        return this->queue[this->frontP];
    }

    void pop()
    {
        this->frontP++;
        if(this->frontP==5000)
        {
            this->frontP=0;
        }
    }

    void push(T node)
    {
        this->queue[this->rearP] = node;
        this->rearP++;
        if(this->rearP==5000)
        {
            this->rearP=0;
        }
    }

    bool empty()
    {
        return this->rearP == this->frontP;
    }
private:
    int rearP;
    int frontP;
    T queue[5000];
};

struct Node
{
    int x,y,time;
}startNode,targetNode;

bool input()
{
    if(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(graph,'*',sizeof(graph));
        for(int i=1;i<=m;i++)
        {
            scanf("%s",graph[i]+1);
        }
    }
    else
    {
        return false;
    }
    return true;
}

void init()
{
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]=='S')
            {
                startNode.x=i;
                startNode.y=j;
                startNode.time=0;
            }
            else if(graph[i][j]=='T')
            {
                targetNode.x=i;
                targetNode.y=j;
                targetNode.time=inf;
            }
        }
    }
    memset(visit,false,sizeof(visit));
}

void bfs()
{
    ZsysQueue<Node> queue;
    queue.push(startNode);
    int dir;
    while(!queue.empty())
    {
        Node temp=queue.front();
        if(temp.x==targetNode.x && temp.y==targetNode.y)
        {
            minTime=temp.time;
            return;
        }
        Node newNode;
        for(int i=0;i<4;i++)
        {
            newNode.x=temp.x+stepX[i];
            newNode.y=temp.y+stepY[i];
            newNode.time=temp.time+1;
            dir=0;
            if(!visit[newNode.x][newNode.y])
            {
                switch(graph[newNode.x][newNode.y])
                {
                case 'T':
                case '.':
                    queue.push(newNode);
                    visit[newNode.x][newNode.y]=true;
                    break;
                case '|':
                    dir=1;
                case '-':
                    newNode.x+=stepX[i];
                    newNode.y+=stepY[i];
                    if((dir+temp.time+i)&1)
                    {
                        if(graph[newNode.x][newNode.y]!='*' && !visit[newNode.x][newNode.y])
                        {
                            queue.push(newNode);
                            visit[newNode.x][newNode.y]=true;
                        }
                    }
                    else
                    {
                        if(graph[newNode.x][newNode.y]!='*' && !visit[newNode.x][newNode.y])
                        {
                            newNode.x=temp.x;
                            newNode.y=temp.y;
                            queue.push(newNode);
                            visit[newNode.x][newNode.y]=true;
                        }
                    }
                }
            }
        }
        queue.pop();
    }
}

void output()
{
    printf("%d\n",minTime);
}

int main(int argc, char *argv[])
{
	while(input())
	{
	    init();
	    bfs();
	    output();
	}
	return 0;
}

/*
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 300

template<typename TYPE, int SIZE>
class Queue
{
    public:
        inline Queue(void)
        {
            this->clear();
        }
        inline void clear(void)
        {
            this->r=0, this->f=0;
        }
        inline void push(TYPE element)
        {
            this->array[this->f++]=element;
        }
        inline void pop(void)
        {
            ++this->r;
        }
        inline const TYPE front(void) const
        {
            return this->array[this->r];
        }
        inline bool empty(void) const
        {
            return this->r>=this->f;
        }
    private:
        int r;
        int f;
        TYPE array[SIZE];
};

struct Node
{
    int floor;
    int time;
    Node(int floorValue = 0, int timeValue = 0)
    {
        floor = floorValue;
        time = timeValue;
    }
};

bool visit[MAXN];
int floor[MAXN],floorNumber,source,target;

int main(int argc, char *argv[])
{
    while(scanf("%d",&floorNumber),floorNumber)
    {
        scanf("%d%d",&source,&target);
        for(int i=1;i<=floorNumber;++i)
        {
            scanf("%d",&floor[i]);
            visit[i]=false;
        }
        Queue<Node, MAXN> queue;
        queue.push(Node(source,0));
        visit[source]=true;
        int answer=-1;
        while(!queue.empty())
        {
            Node rear=queue.front();
            Node front;
            front.time=rear.time+1;
            front.floor=rear.floor+floor[rear.floor];
            if(front.floor>0 && front.floor<=floorNumber)
            {
                if(!visit[front.floor])
                {
                    if(front.floor==target)
                    {
                        answer = front.time;
                        break;
                    }
                    queue.push(front);
                    visit[front.floor]=true;
                }
            }
            front.floor=rear.floor-floor[rear.floor];
            if(front.floor>0 && front.floor<=floorNumber)
            {
                if(!visit[front.floor])
                {
                    if(front.floor==target)
                    {
                        answer = front.time;
                        break;
                    }
                    queue.push(front);
                    visit[front.floor]=true;
                }
            }
            queue.pop();
        }
        printf("%d\n",answer);
    }
    return 0;
}
*/
#include <stdio.h>
#include <string.h>
#define MAXSIZE 210
int N,A,B,number[MAXSIZE],queue[MAXSIZE],step[MAXSIZE],front,rear;
void bfs()
{
    while(front<rear)
    {
        int next,f=queue[++front];
        if(f==B)
        {
            printf("%d\n",step[f]);
            return;
        }
        next=f+number[f];
        if(next <= N && !step[next])
        {
            queue[++rear]=next;
            step[next]=step[f]+1;
        }
        next=f-number[f];
        if(next>0 && !step[next])
        {
            queue[++rear]=next;
            step[next]=step[f]+1;
        }
    }
    printf("-1\n");
}
int main()
{
    while(scanf("%d",&N),N)
    {
        scanf("%d%d",&A,&B);
        for(int i=1; i<=N; i++) scanf("%d",&number[i]);
        memset(step,0,sizeof(step));
        front=rear=-1;
        queue[++rear]=A;
        bfs();
    }
    return 0;
}

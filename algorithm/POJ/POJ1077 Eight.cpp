#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 362881
struct Node
{
    int state[3][3];
    int pre,dir;
    void printState()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                printf("%d ", state[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}queue[MAX];
int cantor[9]={1,1,2,6,24,120,720,5040,40320};
int rear, front, step[MAX], len;
bool visited[MAX];
int hash(int a[3][3])
{
    int b[9],k=0,result=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            b[k++]=a[i][j];
        }
    }
    for(int i=0;i<9;i++)
    {
        int num=0;
        for(int j=0;j<i;j++)
        {
            if(b[j]>b[i])
            {
                num++;
            }
        }
        result+=cantor[i]*num;
    }
    return result;
}

void input()
{
    char s[10];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%s",s);
            if(s[0]=='x')  s[0]='9';
            queue[0].state[i][j]=s[0]-'0';
        }
    }
}

void makeResult()
{
    len=0;
    while(queue[front].pre!=-1)
    {
        step[len++]=queue[front].dir;
        front=queue[front].pre;
    }
}

void output()
{
    for(int i=len-1;i>=0;i--)
    {
        switch(step[i])
        {
            case 0: printf("l"); break;
            case 1: printf("u"); break;
            case 2: printf("r"); break;
            case 3: printf("d"); break;
        }
    }
    printf("\n");
}

bool complete()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i*3+j+1!=queue[front].state[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool bfs()
{
    queue[0].pre=-1;
    queue[0].dir=-1;
    rear=0,front=1;
    visited[hash(queue[0].state)]=true;
    if(complete()) return true;
    while(rear<front)
    {
        int nx,ny;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(queue[rear].state[i][j]==9)
                {
                    nx=i,ny=j;
                }
            }
        }
        if(ny>0)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    queue[front].state[i][j]=queue[rear].state[i][j];
                }
            }
            queue[front].state[nx][ny]^=queue[front].state[nx][ny-1];
            queue[front].state[nx][ny-1]^=queue[front].state[nx][ny];
            queue[front].state[nx][ny]^=queue[front].state[nx][ny-1];
            int temp=hash(queue[front].state);
            if(!visited[temp])
            {
                visited[temp]=true;
                queue[front].pre=rear;
                queue[front].dir=0;
                if(complete())
                {
                    return true;
                }
                front++;
            }
        }
        if(nx>0)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    queue[front].state[i][j]=queue[rear].state[i][j];
                }
            }
            queue[front].state[nx][ny]^=queue[front].state[nx-1][ny];
            queue[front].state[nx-1][ny]^=queue[front].state[nx][ny];
            queue[front].state[nx][ny]^=queue[front].state[nx-1][ny];
            int temp=hash(queue[front].state);
            if(!visited[temp])
            {
                visited[temp]=true;
                queue[front].pre=rear;
                queue[front].dir=1;
                if(complete())
                {
                    return true;
                }
                front++;
            }
        }
        if(ny<2)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    queue[front].state[i][j]=queue[rear].state[i][j];
                }
            }
            queue[front].state[nx][ny]^=queue[front].state[nx][ny+1];
            queue[front].state[nx][ny+1]^=queue[front].state[nx][ny];
            queue[front].state[nx][ny]^=queue[front].state[nx][ny+1];
            int temp=hash(queue[front].state);
            if(!visited[temp])
            {
                visited[temp]=true;
                queue[front].pre=rear;
                queue[front].dir=2;
                if(complete())
                {
                    return true;
                }
                front++;
            }
        }
        if(nx<2)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    queue[front].state[i][j]=queue[rear].state[i][j];
                }
            }
            queue[front].state[nx][ny]^=queue[front].state[nx+1][ny];
            queue[front].state[nx+1][ny]^=queue[front].state[nx][ny];
            queue[front].state[nx][ny]^=queue[front].state[nx+1][ny];
            int temp=hash(queue[front].state);
            if(!visited[temp])
            {
                visited[temp]=true;
                queue[front].pre=rear;
                queue[front].dir=3;
                if(complete())
                {
                    return true;
                }
                front++;
            }
        }
        rear++;
    }
    return false;
}

int main()
{
    input();
    if(bfs())
    {
        makeResult();
        output();
    }
    else
    {
        printf("unsolvable\n");
    }
    return 0;
}

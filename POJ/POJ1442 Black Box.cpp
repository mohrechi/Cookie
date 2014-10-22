#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXM 31000
#define INF 2100000000

//#define DEBUG

class Heap
{
public:
    Heap()
    {
        this->setAscending(true);
        this->clear();
    }
    bool isEmpty() const
    {
        return 0 == this->nodeNumber;
    }
    bool isFull() const
    {
        return MAXM - 1 == this->nodeNumber;
    }
    void clear()
    {
        this->nodeNumber = 0;
    }
    void setAscending(bool value)
    {
        this->ascending = value;
        this->setHead();
    }
    void setDescending(bool value)
    {
        this->ascending = !value;
        this->setHead();
    }
    void push(const int number)
    {
        if(!this->isFull())
        {
            int i;
            if(this->ascending)
            {
                for(i=++this->nodeNumber;number<this->node[i>>1];i>>=1)
                {
                    this->node[i] = this->node[i>>1];
                }
                this->node[i] = number;
            }
            else
            {
                for(i=++this->nodeNumber;number>this->node[i>>1];i>>=1)
                {
                    this->node[i] = this->node[i>>1];
                }
                this->node[i] = number;
            }
        }
    }
    void pop()
    {
        if(!this->isEmpty())
        {
            int lastNode = this->node[this->nodeNumber--];
            int i, next;
            if(this->ascending)
            {
                for(i=1;(i<<1)<=this->nodeNumber;i=next)
                {
                    next = i<<1;
                    if(this->node[next] > this->node[next + 1])
                    {
                        ++next;
                    }
                    if(lastNode > this->node[next])
                    {
                        this->node[i] = this->node[next];
                    }
                    else
                    {
                        break;
                    }
                }
                this->node[i] = lastNode;
            }
            else
            {
                for(i=1;(i<<1)<=this->nodeNumber;i=next)
                {
                    next = i<<1;
                    if(this->node[next] < this->node[next + 1])
                    {
                        ++next;
                    }
                    if(lastNode < this->node[next])
                    {
                        this->node[i] = this->node[next];
                    }
                    else
                    {
                        break;
                    }
                }
                this->node[i] = lastNode;
            }
        }
    }
    int top() const
    {
        return this->node[1];
    }
    #ifdef DEBUG
    void print() const
    {
        if(this->ascending)
        {
            printf("Small ");
        }
        else
        {
            printf("Big ");
        }
        printf("Heap Test: \n");
        for(int i=1;i<=this->nodeNumber;++i)
        {
            printf(" %d",this->node[i]);
        }
        printf("\n");
    }
    #endif
private:
    int node[MAXM];
    int nodeNumber;
    bool ascending;
    void setHead()
    {
        if(this->ascending)
        {
            this->node[0] = -INF;
        }
        else
        {
            this->node[0] = INF;
        }
    }
};

Heap *small, big;
int n,m;
int a[MAXM], b[MAXM];

int main(int argc, char *argv[])
{
    Heap *small = new Heap();
    Heap *big = new Heap();
    big->setDescending(true);
    while(~scanf("%d%d",&m,&n))
    {
        small->clear();
        big->clear();
        for(int i=0;i<m;++i)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&b[i]);
        }
        b[n] = INF;
        int getIndex = 0;
        int addIndex = 0;
        for(int i=0;i<n;++i)
        {
            for(;addIndex<b[getIndex];++addIndex)
            {
                small->push(a[addIndex]);
                big->push(small->top());
                small->pop();
                small->push(big->top());
                big->pop();
                #ifdef DEBUG
                printf("AddIndex: %d\n",addIndex);
                big->print();
                small->print();
                printf("\n");
                #endif
            }
            #ifndef DEBUG
            printf("%d\n",small->top());
            #endif
            big->push(small->top());
            small->pop();
            ++getIndex;
            #ifdef DEBUG
            printf("GetIndex: %d\n", getIndex);
            big->print();
            small->print();
            printf("\n");
            #endif
        }
    }
    return 0;
}

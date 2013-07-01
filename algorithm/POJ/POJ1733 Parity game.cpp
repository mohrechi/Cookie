#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 10005
//#define DEBUG
struct Node
{
    int from, to;
    bool parity;
    void input()
    {
        char s[10];
        scanf("%d%d%s",&from,&to,s);
        parity = 'o' == *s;
    }
}node[MAXN];
int length, nodeNumber;

class Map
{
public:
    void initial()
    {
        this->mapNumber = 0;
    }
    int getMap(int x)
    {
        for(int i=0;i<this->mapNumber;++i)
        {
            if(x == map[i])
            {
                return i;
            }
        }
        this->map[this->mapNumber] = x;
        return this->mapNumber ++;
    }
    int getOrigin(int x)
    {
        return this->map[x];
    }
private:
    int map[MAXN], mapNumber;
};

class Connection
{
public:
    void initial()
    {
        for(int i=0;i<MAXN;++i)
        {
            this->father[i] = i;
            this->relation[i] = false;
        }
        this->error = false;
    }
    int find(int x)
    {
        if(this->father[x] == x)
        {
            return x;
        }
        int temp = this->father[x];
        this->father[x] = this->find(father[x]);
        this->relation[x] = this->relation[temp] ^ this->relation[x];
        return this->father[x];
    }
    void combine(int x, int y, bool parity, Map *map)
    {
        #ifdef DEBUG
        printf("Parity: %d\n",parity);
        #endif
        x = map->getMap(x - 1);
        y = map->getMap(y);
        #ifdef DEBUG
        printf("Map: %d %d\n",x,y);
        #endif
        int rx = this->find(x);
        int ry = this->find(y);
        #ifdef DEBUG
        printf("Root: %d %d\n",rx, ry);
        #endif
        if(rx == ry)
        {
            if(this->relation[x] ^ this->relation[y] ^ parity)
            {
                this->error = true;
                return;
            }
        }
        else
        {
            #ifdef DEBUG
            printf("Origin: %d %d\n",map->getOrigin(rx),map->getOrigin(ry));
            printf("Parity: %d %d %d\n",this->relation[x], this->relation[y], parity);
            #endif
            if(map->getOrigin(rx) < map->getOrigin(ry))
            {
                this->father[ry] = rx;
                this->relation[ry] = this->relation[x] ^ this->relation[y] ^ parity;
            }
            else
            {
                this->father[rx] = ry;
                this->relation[rx] = this->relation[x] ^ this->relation[y] ^ parity;
            }
        }
    }
    bool isError()
    {
        return this->error;
    }
    bool isCorrect()
    {
        return not this->error;
    }
    void output(int x)
    {
        printf("Node %d\tFather: %d  Relation: %d\n", x, father[x], relation[x]);
    }
private:
    int father[MAXN];
    bool relation[MAXN];
    bool error;
};

int main(int argc, char *argv[])
{
    while(~scanf("%d%d",&length, &nodeNumber))
    {
        Map *map = new Map();
        map->initial();
        for(int i=0;i<nodeNumber;++i)
        {
            node[i].input();
        }
        Connection *connection = new Connection();
        connection->initial();
        for(int i=0;i<nodeNumber;++i)
        {
            connection->combine(node[i].from, node[i].to, node[i].parity, map);
            if(connection->isError())
            {
                printf("%d\n", i);
                break;
            }
            #ifdef DEBUG
            for(int j=0;j<5;++j)
            {
                connection->output(j);
            }
            printf("\n");
            #endif
        }
        if(connection->isCorrect())
        {
            printf("%d\n", nodeNumber);
        }
    }
    return 0;
}

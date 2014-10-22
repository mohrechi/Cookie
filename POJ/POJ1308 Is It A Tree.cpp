#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 200

struct Edge
{
    int from, to;
}edge[MAXN*MAXN];
int in[MAXN], edgeNumber;
int numberRecord[MAXN], recordNumber;
bool visit[MAXN];

int getRecord(int x)
{
    for(int i=0;i<recordNumber;++i)
    {
        if(numberRecord[i] == x)
        {
            return i;
        }
    }
    numberRecord[recordNumber] = x;
    return recordNumber++;
}

void paint(int position)
{
    if(!visit[position])
    {
        visit[position] = true;
        for(int i=0;i<edgeNumber;++i)
        {
            if(edge[i].from == position)
            {
                paint(edge[i].to);
            }
        }
    }
}

bool search(int start)
{
    memset(visit, false, sizeof(visit));
    paint(start);
    for(int i=0;i<recordNumber;++i)
    {
        if(!visit[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int caseNumber = 0;
    while(scanf("%d%d",&edge[0].from, &edge[0].to), edge[0].from + 1 || edge[0].to + 1)
    {
        if(edge[0].from == 0 && edge[0].to == 0)
        {
            printf("Case %d is a tree.\n", ++caseNumber);
            continue;
        }
        edgeNumber = 1;
        recordNumber = 0;
        memset(in,0,sizeof(in));
        edge[0].from = getRecord(edge[0].from);
        edge[0].to = getRecord(edge[0].to);
        ++in[edge[0].to];
        while(scanf("%d%d",&edge[edgeNumber].from,&edge[edgeNumber].to), edge[edgeNumber].from || edge[edgeNumber].to)
        {
            edge[edgeNumber].from = getRecord(edge[edgeNumber].from);
            edge[edgeNumber].to = getRecord(edge[edgeNumber].to);
            ++in[edge[edgeNumber].to];
            ++edgeNumber;
        }
        bool flag = false;
        int position;
        for(int i=0;i<recordNumber;++i)
        {
            if(in[i]>1)
            {
                flag = false;
                break;
            }
            if(in[i] == 0)
            {
                if(flag)
                {
                    flag = false;
                    break;
                }
                else
                {
                    flag = true;
                    position = i;
                }
            }
        }
        printf("Case %d is ", ++caseNumber);
        if(flag && search(position))
        {
            printf("a tree.\n");
        }
        else
        {
            printf("not a tree.\n");
        }
    }
    return 0;
}

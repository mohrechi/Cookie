#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXN 15
#define Cannot !
#define reach search(0, i)

int roomNumber, alienRoom;
bool map[MAXN][MAXN];
bool visit[MAXN];
int length[MAXN][MAXN];

void floyd()
{
    for(int i=0;i<roomNumber;++i)
    {
        length[i][i] = 0;
    }
    for(int k=0;k<roomNumber;++k)
    {
        for(int i=0;i<roomNumber;++i)
        {
            for(int j=0;j<roomNumber;++j)
            {
                if(length[i][j] > length[i][k] + length[k][j])
                {
                    length[i][j] = length[i][k] + length[k][j];
                }
            }
        }
    }
}

bool search(int x, int forbid)
{
    if(x == forbid)
    {
        return false;
    }
    if(not visit[x])
    {
        visit[x] = true;
        for(int i=0;i<roomNumber;i++)
        {
            if(i != forbid and not visit[i] and map[x][i])
            {
                if(i == alienRoom or search(i, forbid))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    scanf("%d%d",&roomNumber,&alienRoom);
    int x,y;
    for(int i=0;i<roomNumber;++i)
    {
        for(int j=0;j<roomNumber;++j)
        {
            map[i][j] = false;
            length[i][j] = 200;
        }
    }
    while(EOF!=scanf("%d%d",&x,&y))
    {
        map[x][y] = true;
        length[x][y] = 1;
    }
    floyd();
    int minLength = 200;
    int result;
    for(int i=0;i<roomNumber;++i)
    {
        if(i == alienRoom)
        {
            continue;
        }
        for(int j=0;j<roomNumber;++j)
        {
            visit[j] = false;
        }
        if(length[i][alienRoom] < minLength)
        {
            if(Cannot reach)
            {
                minLength = length[i][alienRoom];
                result = i;
            }
        }
    }
    printf("Put guards in room %d.\n",result);
    return 0;
}

#include <cstdio>
static const int MAXN = 35;
static const int directionX[] = {1, -1, 0, 0, 0, 0};
static const int directionY[] = {0, 0, 1, -1, 0, 0};
static const int directionZ[] = {0, 0, 0, 0, 1, -1};

int level, width, height;
bool dungeon[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
typedef struct
{
    int x, y, z, step;
}Point3d;
Point3d queue[MAXN*MAXN*MAXN];
Point3d startPosition, endPosition;
int front, rear;

bool haveRock(int x, int y, int z)
{
    if(x>=0)
    {
        if(x<level)
        {
            if(y>=0)
            {
                if(y<height)
                {
                    if(z>=0)
                    {
                        if(z<width)
                        {
                            return dungeon[x][y][z];
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    char input[MAXN];
    while(scanf("%d%d%d",&level,&height,&width), level||height||width)
    {
        for(int x=0;x<level;++x)
        {
            for(int y=0;y<height;++y)
            {
                scanf("%s", input);
                for(int z=0;z<width;++z)
                {
                    switch(input[z])
                    {
                        case 'S':
                            startPosition.x = x;
                            startPosition.y = y;
                            startPosition.z = z;
                            startPosition.step = 0;
                            dungeon[x][y][z] = false;
                            break;
                        case 'E':
                            endPosition.x = x;
                            endPosition.y = y;
                            endPosition.z = z;
                        case '.':
                            dungeon[x][y][z] = false;
                            break;
                        case '#':
                            dungeon[x][y][z] = true;
                            break;
                    }
                    visited[x][y][z] = false;
                }
            }
        }
        bool find = false;
        visited[startPosition.x][startPosition.y][startPosition.z] = true;
        queue[0] = startPosition;
        rear = 0, front = 1;
        while(rear < front && !find)
        {
            for(int direction=0;direction<6;++direction)
            {
                Point3d tempPoint = queue[rear];
                tempPoint.x += directionX[direction];
                tempPoint.y += directionY[direction];
                tempPoint.z += directionZ[direction];
                ++tempPoint.step;
                if(!haveRock(tempPoint.x, tempPoint.y, tempPoint.z))
                {
                    if(!visited[tempPoint.x][tempPoint.y][tempPoint.z])
                    {
                        visited[tempPoint.x][tempPoint.y][tempPoint.z] = true;
                        queue[front++] = tempPoint;
                        if(tempPoint.x == endPosition.x)
                        {
                            if(tempPoint.y == endPosition.y)
                            {
                                if(tempPoint.z == endPosition.z)
                                {
                                    find = true;
                                    endPosition.step = tempPoint.step;
                                }
                            }
                        }
                    }
                }
            }
            ++ rear;
        }
        if(find)
        {
            printf("Escaped in %d minute(s).\n", endPosition.step);
        }
        else
        {
            printf("Trapped!\n");
        }
    }
    return 0;
}

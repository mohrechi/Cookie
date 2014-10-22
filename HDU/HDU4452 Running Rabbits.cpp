#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

inline int getDir()
{
    char s[4];
    scanf("%s", s);
    switch(*s)
    {
    case 'N': return 0;
    case 'E': return 1;
    case 'S': return 2;
    case 'W': return 3;
    }
    return -1;
}

struct Rabbit
{
    int x, y, dir;
    int speed, turn;
    int stageSize;
    inline void init()
    {
        dir = getDir();
        scanf("%d%d", &speed, &turn);
    }
    inline void initType_0()
    {
        x = y = 1;
        init();
    }
    inline void initType_1()
    {
        x = y = stageSize;
        init();
    }
    inline void turnLeft()
    {
        dir = (dir + 3) % 4;
    }
    inline void turnAround()
    {
        dir = (dir + 2) % 4;
    }
    void move()
    {
        int tx = x + dirX[dir];
        int ty = y + dirY[dir];
        if(tx >= 1 && tx <= stageSize && ty >= 1 && ty <= stageSize)
        {
            x = tx;
            y = ty;
        }
        else
        {
            turnAround();
            move();
        }
    }
    inline void moveAll()
    {
        for(int i=0;i<speed;++i)
        {
            move();
        }
    }
    inline void output()
    {
        printf("%d %d\n", x, y);
    }
} rabbit[2];

bool operator == (const Rabbit &a, const Rabbit &b)
{
    return a.x == b.x && a.y == b.y;
}

int main()
{
    int n, k;
    while(scanf("%d", &n), n)
    {
        rabbit[0].stageSize = n;
        rabbit[1].stageSize = n;
        rabbit[0].initType_0();
        rabbit[1].initType_1();
        scanf("%d", &k);
        for(int i=1;i<=k;++i)
        {
            rabbit[0].moveAll();
            rabbit[1].moveAll();
            if(rabbit[0] == rabbit[1])
            {
                swap(rabbit[0].dir, rabbit[1].dir);
            }
            else
            {
                if(i % rabbit[0].turn == 0)
                {
                    rabbit[0].turnLeft();
                }
                if(i % rabbit[1].turn == 0)
                {
                    rabbit[1].turnLeft();
                }
            }
        }
        rabbit[0].output();
        rabbit[1].output();
    }
    return 0;
}

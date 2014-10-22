#include <cstdio>
#include <cstring>
const int MAXN = 5005;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

char stage[MAXN];
int dist[MAXN];
int r, c, cost;
int px[MAXN], py[MAXN], pnum;
int sx, sy, ex, ey;
int queue[MAXN];
int visit[MAXN];

inline int getRow(int pos)
{
    return pos / c;
}

inline int getColumn(int pos)
{
    return pos % c;
}

inline int getPos(int x, int y)
{
    return x * c + y;
}

void bfs()
{
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    visit[getPos(sx, sy)] = true;
    dist[getPos(sx, sy)] = 0;
    int front = 0, rear = 1;
    queue[0] = getPos(sx, sy);
    while(front < rear)
    {
        int pos = queue[front ++];
        int x = getRow(pos);
        int y = getColumn(pos);
        for(int i=0;i<4;++i)
        {
            int tx = x + dirX[i];
            int ty = y + dirY[i];
            int tpos = getPos(tx, ty);
            if(tx >= 0 && tx < r)
            {
                if(ty >= 0 && ty < c)
                {
                    if(!visit[tpos])
                    {
                        visit[tpos] = true;
                        switch(stage[tpos])
                        {
                            case '*':
                                dist[tpos] = dist[pos] + cost;
                                queue[rear++] = tpos;
                                break;
                            case '#':
                                break;
                            case 'P':
                                dist[tpos] = dist[pos];
                                queue[rear++] = tpos;
                                for(int i=0;i<pnum;++i)
                                {
                                    int ppos = getPos(px[i], py[i]);
                                    dist[ppos] = dist[pos];
                                    visit[ppos] = true;
                                    queue[rear++] = ppos;
                                }
                                pnum = 0;
                                break;
                            case 'C':
                                dist[tpos] = dist[pos];
                                return;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d", &r, &c, &cost))
    {
        char *temp = stage;
        pnum = 0;
        for(int i=0;i<r;++i)
        {
            scanf("%s", temp);
            for(int j=0;j<c;++j)
            {
                if(temp[j] == 'Y')
                {
                    sx = i, sy = j;
                }
                else if(temp[j] == 'C')
                {
                    ex = i, ey = j;
                }
                else if(temp[j] == 'P')
                {
                    px[pnum] = i;
                    py[pnum++] = j;
                }
            }
            temp += c;
        }
        bfs();
        if(dist[getPos(ex, ey)] == -1)
        {
            printf("Damn teoy!\n");
        }
        else
        {
            printf("%d\n", dist[getPos(ex, ey)]);
        }
    }
    return 0;
}

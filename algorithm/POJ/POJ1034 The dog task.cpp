#include <math.h>
#include <stdio.h>
#include <memory.h>

//#define DEBUG

const int MAXN = 105;
struct Point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
    void output()
    {
        printf("%d %d",x,y);
    }
    double distance(Point otherPoint)
    {
        return sqrt((double)((otherPoint.x - x) * (otherPoint.x - x) + (otherPoint.y - y) * (otherPoint.y - y)));
    }
}hunterRoute[MAXN], dogInterest[MAXN];
int hunterNumber, dogNumber;
double distance[MAXN][MAXN];
bool visited[MAXN];
int link[MAXN],hunterLink[MAXN];

void input()
{
    scanf("%d%d",&hunterNumber,&dogNumber);
    for(int i=1;i<=hunterNumber;++i)
    {
        hunterRoute[i].input();
    }
    for(int i=1;i<=dogNumber;++i)
    {
        dogInterest[i].input();
        for(int j=1;j<=hunterNumber;++j)
        {
            distance[j][i] = dogInterest[i].distance(hunterRoute[j]);
        }
    }
    #ifdef DEBUG
        for(int i=1;i<=hunterNumber;++i)
        {
            for(int j=1;j<=dogNumber;++j)
            {
                printf("%.3lf ",distance[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    #endif
}

bool find(int index)
{
    double tempDistance = hunterRoute[index].distance(hunterRoute[index+1]) * 2;
    for(int i=1;i<=dogNumber;++i)
    {
        if(not visited[i])
        {
            if(tempDistance >= distance[index][i] + distance[index+1][i])
            {
                visited[i] = true;
                if(link[i] == 0 or find(link[i]))
                {
                    link[i] = index;
                    return true;
                }
            }
        }
    }
    return false;
}

int hungary()
{
    int count = 0;
    memset(link, 0, sizeof(link));
    for(int i=1;i<hunterNumber;++i)
    {
        memset(visited,false,sizeof(visited));
        if(find(i))
        {
            ++count;
        }
        #ifdef DEBUG
            for(int j=1;j<=hunterNumber;++j)
            {
                printf("%d ",link[j]);
            }
            printf("\n");
        #endif
    }
    return count;
}

void output()
{
    printf("%d\n",hungary() + hunterNumber);
    memset(hunterLink, 0, sizeof(hunterLink));
    for(int i=1;i<=dogNumber;++i)
    {
        if(link[i])
        {
            hunterLink[link[i]] = i;
        }
    }
    for(int i=1;i<=hunterNumber;++i)
    {
        if(i>1)
        {
            printf(" ");
        }
        hunterRoute[i].output();
        if(hunterLink[i])
        {
            printf(" ");
            dogInterest[hunterLink[i]].output();
        }
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    input();
    output();
    return 0;
}

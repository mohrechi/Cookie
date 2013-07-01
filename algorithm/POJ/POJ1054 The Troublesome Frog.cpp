#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
//#define DEBUG
//#define METHOD1
//Method 1: 73784K	2954MS
#define METHOD2
//Method 2: 24716K	1594MS
const int MAXN = 5005;

#ifdef METHOD1
    short riceArea[MAXN][MAXN];
    bool tested[MAXN][MAXN];
#else
    bool riceArea[MAXN][MAXN];
#endif
int row, column;
struct Point
{
    short x, y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
    void output()
    {
        printf("%d %d\n",x,y);
    }
}frogStep[MAXN];
int stepNumber, maximumStep;

void input()
{
    memset(riceArea, false, sizeof(riceArea));
    scanf("%d%d%d",&row,&column,&stepNumber);
    for(int i=0;i<stepNumber;++i)
    {
        frogStep[i].input();
        #ifdef METHOD2
            riceArea[frogStep[i].x][frogStep[i].y] = true;
        #endif
    }
}

int compare(const void *a, const void *b)
{
    if((*(Point*)a).x == (*(Point*)b).x)
    {
        return (*(Point*)a).y - (*(Point*)b).y;
    }
    return (*(Point*)a).x - (*(Point*)b).x;
}

bool outOfBounary(int x, int y)
{
    return x < 1 || x > row || y < 1 || y > column;
}

void findFrogStep()
{
    bool frogFlag, waterFlag;
    int currentFrogStep;
    int diffX, diffY;
    int testX, testY;
    Point tempStep;
    #ifdef METHOD1
        memset(tested, false, sizeof(tested));
    #endif
    maximumStep = 0;
    for(int i=0;i<stepNumber;++i)
    {
        for(int j=i+1;j<stepNumber;++j)
        {
            #ifdef METHOD1
            if(!tested[i][j])
            {
            #endif
                diffX = frogStep[j].x - frogStep[i].x;
                diffY = frogStep[j].y - frogStep[i].y;
                testX = frogStep[i].x - diffX;
                testY = frogStep[i].y - diffY;
                if(testX >= 1 && testX <= row && testY >= 1 && testY <= column)
                {
                    continue;
                }
                currentFrogStep = 2;
                frogFlag = true;
                waterFlag = false;
                tempStep.x = frogStep[j].x;
                tempStep.y = frogStep[j].y;
                while(frogFlag)
                {
                    tempStep.x += diffX;
                    tempStep.y += diffY;
                    if(outOfBounary(tempStep.x, tempStep.y))
                    {
                        break;
                    }
                    if(riceArea[tempStep.x][tempStep.y])
                    {
                        #ifdef METHOD1
                            tested[riceArea[tempStep.x][tempStep.y]-1][riceArea[tempStep.x - diffX][tempStep.y - diffY]-1] = true;
                            tested[riceArea[tempStep.x - diffX][tempStep.y - diffY]-1][riceArea[tempStep.x][tempStep.y]-1] = true;
                        #endif
                        ++currentFrogStep;
                    }
                    else
                    {
                        frogFlag = false;
                    }
                }
                if(frogFlag)
                {
                    if(currentFrogStep>maximumStep)
                    {
                        maximumStep = currentFrogStep;
                    }
                }
            #ifdef METHOD1
            }
            #endif
        }
    }
}

int main(int argc, char* argv[])
{
    input();
    qsort(frogStep, stepNumber, sizeof(*frogStep), compare);
    #ifdef METHOD1
        for(int i=0;i<stepNumber;++i)
        {
            riceArea[frogStep[i].x][frogStep[i].y] = i+1;
        }
    #endif
    #ifdef DEBUG
        printf("Sorted Points: \n");
        for(int i=0;i<stepNumber;++i)
        {
            frogStep[i].output();
        }
    #endif
    findFrogStep();
    if(maximumStep < 3)
    {
        maximumStep = 0;
    }
    printf("%d\n",maximumStep);
    return 0;
}

#include<stdio.h>
#include<memory.h>
//#define DEBUG
enum Direction
{
    LEFT, RIGHT, UP, DOWN, NOTSURE
};
const int MAXN = 105;

char logicMap[MAXN][MAXN];
char logicAlpha[30];
int resultX, resultY;

bool inputLogicMap()
{
    int line = 0;
    char* flag;
    memset(logicMap,0,sizeof(logicMap));
    while(flag = gets(logicMap[++line]+1),*(logicMap[line]+1)!='*' && flag!=NULL);
    return flag != NULL;
}

void getResultPosition()
{
    for(int i=0;i<MAXN;++i)
    {
        for(int j=0;j<MAXN;++j)
        {
            if(logicMap[i][j] == '?')
            {
                resultX = i;
                resultY = j;
                return;
            }
        }
    }
}

bool isAlpha(char ch)
{
    return ch>='A' && ch <='Z';
}

bool getLogic(int x, int y, Direction direction)
{
    #ifdef DEBUG
        printf("Position: x %d, y %d  Direction: %d\n",x,y,direction);
    #endif
    switch(logicMap[x][y])
    {
        case '?':
            if(logicMap[x][y-1] == '-')
            {
                return getLogic(x,y-1,LEFT);
            }
            else if(logicMap[x][y+1] == '-')
            {
                return getLogic(x,y+1,RIGHT);
            }
            else if(logicMap[x-1][y] == '|')
            {
                return getLogic(x-1,y,UP);
            }
            else
            {
                return getLogic(x+1,y,DOWN);
            }
            break;
        case '-':
            if(direction == LEFT)
            {
                return getLogic(x,y-1,LEFT);
            }
            else
            {
                return getLogic(x,y+1,RIGHT);
            }
            break;
        case '|':
            if(direction == UP)
            {
                return getLogic(x-1,y,UP);
            }
            else
            {
                return getLogic(x+1,y,DOWN);
            }
            break;
        case '+':
            if(direction == UP || direction == DOWN)
            {
                if(logicMap[x][y-1] == '-')
                {
                    return getLogic(x,y-1,LEFT);
                }
                else
                {
                    return getLogic(x,y+1,RIGHT);
                }
            }
            else
            {
                if(logicMap[x-1][y] == '|')
                {
                    return getLogic(x-1,y,UP);
                }
                else
                {
                    return getLogic(x+1,y,DOWN);
                }
            }
            break;
        case 'o':
            if((logicMap[x][y-1] == '-' || logicMap[x][y-1] == ')' || logicMap[x][y-1] == '>') && direction!=RIGHT)
            {
                return !getLogic(x,y-1,LEFT);
            }
            else if(logicMap[x][y+1] == '-' && direction!=LEFT)
            {
                return !getLogic(x,y+1,RIGHT);
            }
            else if(logicMap[x-1][y] == '|' && direction!=DOWN)
            {
                return !getLogic(x-1,y,UP);
            }
            else
            {
                return !getLogic(x+1,y,DOWN);
            }
            break;
        case ')':
            return getLogic(x-1,y-3,LEFT) && getLogic(x+1,y-3,LEFT);
        case '>':
            return getLogic(x-1,y-3,LEFT) || getLogic(x+1,y-3,LEFT);
        default:
            if(isAlpha(logicMap[x][y]))
            {
                return logicAlpha[logicMap[x][y] - 'A'] == '1';
            }
    }
}

int main(int argc,char* argv[])
{
    bool flag = true;
    while(inputLogicMap())
    {
        if(flag)
        {
            flag = false;
        }
        else
        {
            printf("\n");
        }
        getResultPosition();
        while(scanf("%s",logicAlpha),*logicAlpha!='*')
        {
            printf("%d\n",getLogic(resultX, resultY, NOTSURE));
        }
    }
    return 0;
}

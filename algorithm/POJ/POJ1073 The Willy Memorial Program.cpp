#include <cstdio>
#include <cstring>

//#define DEBUG
//#define METHOD1
#define METHOD2

static const int MAX_PIPE_NUMBER = 20;
static const int MAX_LINK_NUMBER = 50;

struct Pipe
{
    int left, right;
    int top, bottom;
    int height;
    void input()
    {
        scanf("%d%d%d", &left, &top, &height);
        right = left + 1;
        bottom = top + height;
    }
}pipe[MAX_PIPE_NUMBER];

struct Link
{
    int left, right;
    int depth, width;
    void input()
    {
        scanf("%d%d%d", &left, &depth, &width);
        right = left + width;
    }
}link[MAX_LINK_NUMBER];

int pipeNumber, linkNumber;
int spiderPipe, spiderDepth;
bool visited[MAX_PIPE_NUMBER];
bool findAnswer;
int flowTime;

void input()
{
    scanf("%d", &pipeNumber);
    for(int i=0;i<pipeNumber;++i)
    {
        pipe[i].input();
    }
    scanf("%d", &linkNumber);
    for(int i=0;i<linkNumber;++i)
    {
        link[i].input();
    }
    scanf("%d%d", &spiderPipe, &spiderDepth);
    -- spiderPipe;
}

#if defined(METHOD1)
int pipeIndexStack[MAX_PIPE_NUMBER];
int pipeTimeStack[MAX_PIPE_NUMBER];
int pipeIndexTop, pipeTimeTop;
void solve()
{
    if(spiderDepth > pipe[spiderPipe].bottom || spiderDepth < pipe[spiderPipe].top)
    {
        findAnswer = false;
        return;
    }
    int topLevel = pipe[0].top;
    int waterLevel = pipe[0].bottom;
    int time = 1;
    bool findPipe;
    pipeIndexTop = 0;
    pipeTimeTop = 0;
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    flowTime = 0;
    while(true)
    {
        findPipe = false;
        for(int i=0;i<linkNumber;++i)
        {
            if(link[i].depth == waterLevel)
            {
                for(int j=0;j<pipeNumber;++j)
                {
                    if(visited[j])
                    {
                        int k;
                        for(k=0;k<pipeNumber;++k)
                        {
                            if((pipe[j].right == link[i].left && pipe[k].left == link[i].right) || (pipe[k].right == link[i].left && pipe[j].left == link[i].right))
                            {
                                if(!visited[k])
                                {
                                    pipeIndexStack[pipeIndexTop++] = j;
                                    pipeTimeStack[pipeTimeTop++] = time;
                                    waterLevel = pipe[k].bottom;
                                    time = 1;
                                    visited[k] = true;
                                    findPipe = true;
                                    if(topLevel < pipe[k].top)
                                    {
                                        topLevel = pipe[k].top;
                                    }
                                }
                                else if(pipeIndexTop != 0 && (pipeIndexStack[pipeIndexTop - 1] == j || pipeIndexStack[pipeIndexTop - 1] == k))
                                {
                                    time = pipeTimeStack[pipeTimeTop - 1];
                                    -- pipeIndexTop;
                                    -- pipeTimeTop;
                                    ++ time;
                                }
                                break;
                            }
                        }
                        if(k < pipeNumber)
                        {
                            break;
                        }
                    }
                }
                break;
            }
        }
        if(findPipe)
        {
            continue;
        }
        if(waterLevel <= topLevel || spiderDepth <= topLevel)
        {
            findAnswer = false;
            return;
        }
        if(visited[spiderPipe] && waterLevel == spiderDepth)
        {
            findAnswer = true;
            return;
        }
        -- waterLevel;
        flowTime += time;
    }
}
#elif defined(METHOD2)
int topLevel;
int fillWater(int pipeIndex)
{
    int currentPipeNumber = 1;
    int waterLevel = pipe[pipeIndex].bottom;
    visited[pipeIndex] = true;
    if(topLevel < pipe[pipeIndex].top)
    {
        topLevel = pipe[pipeIndex].top;
    }
    #ifdef DEBUG
    printf("Index: %d Top: %d Bottom %d\n", pipeIndex + 1, topLevel, waterLevel);
    #endif
    while(true)
    {
        for(int i=0;i<linkNumber;++i)
        {
            if(link[i].depth == waterLevel)
            {
                for(int j=0;j<pipeNumber;++j)
                {
                    if(visited[j])
                    {
                        int k;
                        for(k=0;k<pipeNumber;++k)
                        {
                            if((pipe[j].right == link[i].left && pipe[k].left == link[i].right) || (pipe[k].right == link[i].left && pipe[j].left == link[i].right))
                            {
                                if(!visited[k])
                                {
                                    #ifdef DEBUG
                                    printf("LINK %d ", i + 1);
                                    #endif
                                    currentPipeNumber += fillWater(k);
                                    if(findAnswer)
                                    {
                                        return currentPipeNumber;
                                    }
                                }
                                else if(i == pipeIndex || j == pipeIndex)
                                {
                                    return currentPipeNumber;
                                }
                                break;
                            }
                        }
                        if(k < pipeNumber)
                        {
                            break;
                        }
                    }
                }
                break;
            }
        }
        if(waterLevel <= topLevel || spiderDepth <= topLevel)
        {
            findAnswer = false;
            return currentPipeNumber;
        }
        if(visited[spiderPipe] && waterLevel == spiderDepth)
        {
            findAnswer = true;
            return currentPipeNumber;
        }
        waterLevel--;
        flowTime += currentPipeNumber;
        #ifdef DEBUG
        printf("Index: %d Water: %d Time: %d Number: %d\n", pipeIndex + 1, waterLevel, flowTime, currentPipeNumber);
        #endif
    }
    return currentPipeNumber;
}

void solve()
{
    findAnswer = false;
    if(spiderDepth > pipe[spiderPipe].bottom || spiderDepth < pipe[spiderPipe].top)
    {
        return;
    }
    topLevel = pipe[0].top;
    memset(visited, false, sizeof(visited));
    flowTime = 0;
    fillWater(0);
}
#endif

void output()
{
    if(findAnswer)
    {
        printf("%d\n", flowTime);
    }
    else
    {
        printf("No Solution\n");
    }
}

int main(int argc, char *argv[])
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        input();
        solve();
        output();
    }
    return 0;
}

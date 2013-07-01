#include <cstdio>
#include <cstring>

#ifdef METHOD1

//#define STATIC_TRIANGLE
#ifndef STATIC_TRIANGLE
    #define DYNAMIC_TRIANGLE
#endif

static const int VertexToEdgeMap[11][11] = {{  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},{  0,  0,  1,  2,  0,  0,  0,  0,  0,  0,  0},{  0,  1,  0,  3,  4,  5,  0,  0,  0,  0,  0},{  0,  2,  3,  0,  0,  6,  7,  0,  0,  0,  0},{  0,  0,  4,  0,  0,  8,  0, 10, 11,  0,  0},{  0,  0,  5,  6,  8,  0,  9,  0, 12, 13,  0},{  0,  0,  0,  7,  0,  9,  0,  0,  0, 14, 15},{  0,  0,  0,  0, 10,  0,  0,  0, 16,  0,  0},{  0,  0,  0,  0, 11, 12,  0, 16,  0, 17,  0},{  0,  0,  0,  0,  0, 13, 14,  0, 17,  0, 18},{  0,  0,  0,  0,  0,  0, 15,  0,  0, 18,  0}};
static const int BOARD_EMPTY = 0;
static const int BOARD_FULL = 524286;
static const int NUMBER_EDGE = 18;
static const int NUMBER_TRIANGLE = 9;
static const int Triangle[NUMBER_TRIANGLE] = {14, 304, 104, 704, 68608, 6400, 143360, 25088, 311296};

int initialStatus, prevTriangleNumber;
char triangleNumber[BOARD_FULL];
char triangleStrategy[BOARD_FULL];
int triangleStrategyNext[BOARD_FULL];
int triangleNumberA, triangleNumberB;
bool isATurn;

#ifdef DEBUG
void printAllBits(const int status)
{
    printf("All Bits: ");
    for(int i=1;i<=18;++i)
    {
        printf("%d",(status&(1<<i))>0);
        if(0 == i % 5)
        {
            printf(" ");
        }
        if(0 == i % 10)
        {
            printf(" ");
        }
    }
    printf("\n");
}
#endif

inline const int max(int x, int y)
{
    return x>y?x:y;
}

inline void setBitZero(int &status, const int bit)
{
    status &= ~(1<<bit);
}

inline void setBitOne(int &status, const int bit)
{
    status |= (1<<bit);
}

inline int getBit(const int status, const int bit)
{
    return status & (1<<bit);
}

inline bool isBitZero(const int status, const int bit)
{
    return 0 == getBit(status, bit);
}

inline bool isBitOne(const int status, const int bit)
{
    return 0 < getBit(status, bit);
}

inline int getTriangleNumber(const int status)
{
    if(status == BOARD_FULL)
    {
        return NUMBER_TRIANGLE;
    }
    #ifdef DYNAMIC_TRIANGLE
        if(-1 == triangleNumber[status])
        {
    #endif
            int count = 0;
            for(int i=0;i<NUMBER_TRIANGLE;++i)
            {
                if((status&Triangle[i]) == Triangle[i])
                {
                    ++count;
                }
            }
            #ifdef DYNAMIC_TRIANGLE
                return triangleNumber[status] = count;
            #endif
            return count;
    #ifdef DYNAMIC_TRIANGLE
        }
        return triangleNumber[status];
    #endif
}

void initialTriangleNumber()
{
    #ifdef DYNAMIC_TRIANGLE
        memset(triangleNumber, -1, sizeof(triangleNumber));
    #endif
    #ifdef STATIC_TRIANGLE
        int count;
        for(int i=BOARD_EMPTY;i<=BOARD_FULL;++i)
        {
            triangleNumber[i] = getTriangleNumber(i);
        }
    #endif
}

int getTriangleStrategy(int status)
{
    printAllBits(status);
    if(status == BOARD_FULL)
    {
        return 0;
    }
    if(-1 == triangleStrategy[status])
    {
        int maxTriangle =-1, tempStatus;
        int triangleNumber1, triangleNumber2;
        int currentStatus = status;
        triangleNumber1 = getTriangleNumber(status);
        for(int i=1;i<=NUMBER_EDGE;++i)
        {
            if(isBitZero(status, i))
            {
                setBitOne(status, i);
                triangleNumber2 = getTriangleNumber(status);
                if(triangleNumber2 > triangleNumber1)
                {
                    if(getTriangleStrategy(status) > maxTriangle)
                    {
                        triangleStrategyNext[currentStatus] = status;
                        maxTriangle = getTriangleStrategy(status) + 1;
                    }
                }
                setBitZero(status, i);
            }
        }
        return triangleStrategy[status] = maxTriangle;
    }
    return triangleStrategy[status];
}

void initialTriangleStrategy()
{
    memset(triangleStrategy, -1, sizeof(triangleStrategy));
}

void gameLoop()
{
    int triangleNumberSelf, triangleNumberEnemy;
    int nextStatus, maxDistance, tempStatus;
    int triangleNumber1, triangleNumber2;
    while(BOARD_FULL != initialStatus)
    {
        maxDistance = -100;
        triangleNumber1 = getTriangleNumber(initialStatus);
        for(int i=1;i<=NUMBER_EDGE;++i)
        {
            if(isBitZero(initialStatus, i))
            {
                setBitOne(initialStatus, i);
                triangleNumber2 = getTriangleNumber(initialStatus);
                if(triangleNumber2 > triangleNumber1)
                {
                    triangleNumberSelf = triangleNumber2 - triangleNumber1 + getTriangleStrategy(initialStatus);
                    triangleNumber2 = triangleNumber1;
                    tempStatus = initialStatus;
                    while(triangleNumber2 - triangleNumber1 <= triangleNumberSelf)
                    {
                        tempStatus = triangleStrategyNext[tempStatus];
                        triangleNumber2 = getTriangleNumber(tempStatus);
                    }
                    triangleNumberEnemy = getTriangleStrategy(tempStatus);
                }
                else
                {
                    tempStatus = initialStatus;
                    triangleNumberSelf = 0;
                    triangleNumberEnemy = getTriangleStrategy(initialStatus);
                }
                if(triangleNumberSelf - triangleNumberEnemy > maxDistance)
                {
                    maxDistance = triangleNumberSelf - triangleNumberEnemy;
                    nextStatus = tempStatus;
                }
                setBitZero(initialStatus, i);
            }
        }
        initialStatus = nextStatus;
        if(isATurn)
        {
            triangleNumberA += triangleNumberSelf;
            isATurn = false;
        }
        else
        {
            triangleNumberB += triangleNumberSelf;
            isATurn = true;
        }
    }
}

void input()
{
    int edgeNumber,x,y;
    prevTriangleNumber = 0;
    isATurn = true;
    initialStatus = 0;
    triangleNumberA = 0;
    triangleNumberB = 0;
    scanf("%d",&edgeNumber);
    while(edgeNumber--)
    {
        scanf("%d%d",&x,&y);
        setBitOne(initialStatus, VertexToEdgeMap[x][y]);
        if(getTriangleNumber(initialStatus) > prevTriangleNumber)
        {
            if(isATurn)
            {
                triangleNumberA = getTriangleNumber(initialStatus) - prevTriangleNumber;
            }
            else
            {
                triangleNumberB = getTriangleNumber(initialStatus) - prevTriangleNumber;
            }
            prevTriangleNumber = getTriangleNumber(initialStatus);
        }
        else
        {
            isATurn ^= true;
        }
    }
}

void output(const int caseIndex)
{
    char winner = (triangleNumberA > triangleNumberB?'A':'B');
    printf("Game %d: %c wins.\n",caseIndex,winner);
}

int main(int argc, char* argv[])
{
    int caseNumber;
    initialTriangleNumber();
    initialTriangleStrategy();
    scanf("%d",&caseNumber);
    for(int i=1;i<=caseNumber;++i)
    {
        input();
        gameLoop();
        output(i);
    }
    return 0;
}
#endif
int map[11][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0,0,0},{0,0,0,2,3,4,0,0,0,0,0},{0,1,2,0,0,5,6,0,0,0,0},{0,0,3,0,0,7,0,9,10,0,0},{0,0,4,5,7,0,8,0,11,12,0},{0,0,0,6,0,8,0,0,0,13,14},{0,0,0,0,9,0,0,0,15,0,0},{0,0,0,0,10,11,0,15,0,16,0},{0,0,0,0,0,12,13,0,16,0,17},{0,0,0,0,0,0,0,14,0,17,0}};int tri[9]={7,152,52,352,34304,3200,71680,12544,155648};const int mirror=(1<<18)-1;int MinSearch(int ,int ,int ,int );int MaxSearch(int ,int ,int ,int );int Place(int s,int seg,int &of){int i;int r=s|seg;for(i=0;i<9;i++){if(((tri[i]&s)!=tri[i])&&((tri[i]&r)==tri[i]))of++;}return r;}int MaxSearch(int statu,int alpha,int as,int bs){int bit,seg;int cs,r;int max=-1,tmp;if(as>=5) return 1;if(bs>=5) return -1;if(statu==mirror)return as>bs?1:-1;bit=(~statu)&mirror;while(bit){seg=bit&(-bit);cs=as;r=Place(statu,seg,cs);if(cs>as)tmp=MaxSearch(r,alpha,cs,bs);else tmp=MinSearch(r,max,cs,bs);if(tmp>max) max=tmp;if(max>=alpha)return max;bit-=seg;}return max;}int MinSearch(int statu,int beta,int as,int bs){int bit,seg,cs,r;int min=1,tmp;if(as>=5) return 1;if(bs>=5) return -1;if(statu==mirror)return as>bs?1:-1;bit=(~statu)&mirror;while(bit){seg=bit&(-bit);cs=bs;r=Place(statu,seg,cs);if(cs>bs)tmp=MinSearch(r,beta,as,cs);else tmp=MaxSearch(r,min,as,cs);if(tmp<min) min=tmp;if(tmp<=beta) return min;bit-=seg;}return min;}int main(){int t,k=0;int a,b,n,i,turn;int res;int ofa,ofb;int ta,tb;int status;scanf("%d",&t);while(t--){scanf("%d",&n);status=ofa=ofb=0;for(turn=i=0;i<n;i++){scanf("%d%d",&a,&b);ta=ofa,tb=ofb;status=Place(status,1<<map[a][b],(turn&1)?ofb:ofa);if(ta==ofa&&tb==ofb)turn++;}if(turn&1)res=MinSearch(status,-1,ofa,ofb);else res=MaxSearch(status,1,ofa,ofb);printf("Game %d: %c wins.\n",++k,res==1?'A':'B');}return 0;}

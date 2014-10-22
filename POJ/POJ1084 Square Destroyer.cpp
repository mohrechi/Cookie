#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
    //#define DEBUG1
    //#define DEBUG2
    #define DEBUG3
#endif

int gridLength;
long long grid;
int minimumStep;
int stickTotalNumber;

inline bool isOne(long long number, int bit)
{
    return (number & (((long long)1)<<bit)) > 0;
}

inline bool isZero(long long number, int bit)
{
    return (number & (((long long)1)<<bit)) == 0;
}

#ifdef DEBUG
void printAllBit(long long number)
{
    for(int i=1;i<=stickTotalNumber;++i)
    {
        printf("%d",isOne(number, i));
        if(!(i%5))
        {
            printf(" ");
        }
        if(!(i%10))
        {
            printf("  ");
        }
    }
    printf("\n");
}
#endif

inline void setZero(long long &number, int bit)
{
    number &= ~(((long long)1)<<bit);
}

inline void setOne(long long &number, int bit)
{
    number |= (((long long)1)<<bit);
}

inline void setAllZero(long long &number)
{
    number = 0;
}

inline void setAllOne(long long &number)
{
    for(int bit=1;bit<=stickTotalNumber;++bit)
    {
        number |= (((long long)1)<<bit);
    }
}

void makeSquare(int row, int column, int squareLength, long long &tempGrid)
{
    int horizon,vertical,columnLength;
    setAllZero(tempGrid);
    columnLength = 2 * gridLength + 1;
    horizon = row * columnLength + column + 1;
    vertical = row * columnLength + column + gridLength + 1;
    for(int i=0;i<squareLength;++i)
    {
        setOne(tempGrid, horizon + i);
        setOne(tempGrid, horizon + squareLength * columnLength + i);
        setOne(tempGrid, vertical + columnLength * i);
        setOne(tempGrid, vertical + squareLength + columnLength * i);
        #ifdef DEBUG3
            printf("%d %d %d %d\n",horizon + i, horizon + squareLength * columnLength + i, vertical + columnLength * i, vertical + squareLength + columnLength * i);
            printAllBit(tempGrid);
        #endif
        #ifdef DEBUG2
            if(squareLength > 1)
            {
                printf("%d %d %d %d\n",horizon+i, horizon+columnLength+i,vertical + columnLength * i,vertical + squareLength + columnLength * i);
            }
        #endif
    }
    #ifdef DEBUG2
        if(squareLength > 1)
        {
            printf("Make square %d: ",squareLength);
            printAllBit(tempGrid);
        }
    #endif
}

bool haveSquare(long long tempGrid)
{
    for(int bit=1;bit<=stickTotalNumber;++bit)
    {
        if(isOne(tempGrid, bit))
        {
            if(isZero(grid, bit))
            {
                return false;
            }
        }
    }
    return true;
}

void search(int stepNumber)
{
    if(stepNumber >= minimumStep)
    {
        return;
    }
    bool flag = false;
    for(int squareLength=1;!flag && squareLength<=gridLength;++squareLength)
    {
        int squareEdge = gridLength - squareLength + 1;
        for(int row=0;!flag && row<squareEdge;++row)
        {
            for(int column=0;!flag && column<squareEdge;++column)
            {
                long long tempSqure;
                makeSquare(row, column, squareLength, tempSqure);
                if(haveSquare(tempSqure))
                {
                    #ifdef DEBUG1
                        printf("%d\n",stepNumber);
                        printf("Search: ");
                        printAllBit(grid);
                        printf("Square: ");
                        printAllBit(tempSqure);
                        //while('t' != getchar());
                    #endif
                    flag = true;
                    for(int bit=1;bit<=stickTotalNumber;++bit)
                    {
                        if(isOne(tempSqure, bit))
                        {
                            setZero(grid, bit);
                            search(stepNumber + 1);
                            setOne(grid, bit);
                        }
                    }
                }
            }
        }
    }
    if(!flag)
    {
        if(stepNumber < minimumStep)
        {
            minimumStep = stepNumber;
        }
    }
}

int main(int argc, char* argv[])
{
    #ifdef DEBUG3
        long long temp;
        gridLength = 4;
        stickTotalNumber = 2 * gridLength * (gridLength + 1);
        makeSquare(1,1,3,temp);
        printAllBit(temp);
    #endif
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        minimumStep = 0x7FFFFFFF;
        scanf("%d",&gridLength);
        stickTotalNumber = 2 * gridLength * (gridLength + 1);
        setAllZero(grid);
        setAllOne(grid);
        int stickNumber, stick;
        scanf("%d",&stickNumber);
        for(int i=0;i<stickNumber;++i)
        {
            scanf("%d",&stick);
            setZero(grid, stick);
        }
        search(0);
        printf("%d\n",minimumStep);
    }
    return 0;
}

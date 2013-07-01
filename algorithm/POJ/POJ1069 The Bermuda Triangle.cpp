#include <cstdio>
#include <cstdlib>
#include <cstring>
static const int MaxHexagonalSide = 25 + 5;
static const int MaxTriangleTypeNumber = 10 + 5;
static const int MaxTriangleNumber = MaxHexagonalSide * MaxHexagonalSide * 6;

bool isSizeAvailable[MaxTriangleNumber];
int triangleType[MaxTriangleTypeNumber];
int triangleTypeNumber;
int hexagonalSide;
bool hexagonal[MaxHexagonalSide * 2][MaxHexagonalSide * 4 - 1];
int hexagonalWideStart[MaxHexagonalSide * 2];
int hexagonalWideEnd[MaxHexagonalSide * 2];

bool isHexagonalSideDivisibleByTriangle()
{
    for(int i=0;i<triangleTypeNumber;++i)
    {
        if(0 == hexagonalSide % triangleType[i])
        {
            return true;
        }
    }
    return false;
}

void reduceTriangleTypeNumber()
{
    bool temp[MaxHexagonalSide];
    memset(temp, false, sizeof(temp));
    for(int i=0;i<triangleTypeNumber;++i)
    {
        temp[triangleType[i]] = true;
    }
    for(int i=2;i<MaxHexagonalSide;++i)
    {
        for(int j=1;j<i;++j)
        {
            if(temp[i] && temp[j] && 0 == i % j)
            {
                temp[i] = false;
                break;
            }
        }
    }
    triangleTypeNumber = 0;
    for(int i=1;i<MaxHexagonalSide;++i)
    {
        if(temp[i])
        {
            triangleType[triangleTypeNumber++] = i;
        }
    }
    for(int i=0;i<triangleTypeNumber;++i)
    {
        for(int j=i+1;j<triangleTypeNumber;++j)
        {
            if(triangleType[i] < triangleType[j])
            {
                triangleType[i] ^= triangleType[j];
                triangleType[j] ^= triangleType[i];
                triangleType[i] ^= triangleType[j];
            }
        }
    }
}

void calculateAvailableSize()
{
    memset(isSizeAvailable, false, sizeof(isSizeAvailable));
    isSizeAvailable[0] = true;
    for(int i=0;i<MaxTriangleNumber;++i)
    {
        if(isSizeAvailable[i])
        {
            for(int j=0;j<triangleTypeNumber;++j)
            {
                if(i + triangleType[j] < MaxTriangleNumber)
                {
                    isSizeAvailable[i + triangleType[j]] = true;
                }
            }
        }
    }
}

void calculateHexagonalWide()
{
    for(int i=1;i<=hexagonalSide;++i)
    {
        hexagonalWideStart[i] = 1;
        hexagonalWideEnd[i] = (hexagonalSide << 1) + ((i - 1) << 1) + 1;
    }
    for(int i=1;i<=hexagonalSide;++i)
    {
        hexagonalWideStart[i + hexagonalSide] = (i << 1);
        hexagonalWideEnd[i + hexagonalSide] = (hexagonalSide << 2);
    }
}

bool isInsideHexagonal(const int x, const int y)
{
    if(x >= 1 && x <= (hexagonalSide << 1))
    {
        if(y >= hexagonalWideStart[x] && y <= hexagonalWideEnd[x])
        {
            return true;
        }
    }
    return false;
}

bool couldPlaceTriangle(int x, int y, const int triangleSide)
{
    if(y&1)
    {
        for(int i=0;i<triangleSide;++i)
        {
            for(int j=0;j<(i<<1)+1;++j)
            {
                if(isInsideHexagonal(x+i, y+j))
                {
                    if(hexagonal[x+i][y+j])
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        x += (triangleSide - 1);
        y += (triangleSide - 1) << 1;
        for(int i=0;i<triangleSide;++i)
        {
            for(int j=0;j<(i<<1)+1;++j)
            {
                if(isInsideHexagonal(x-i, y-j))
                {
                    if(hexagonal[x-i][y-j])
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void setTriangle(int x, int y, const int triangleSide, const int status)
{
    if(y&1)
    {
        for(int i=0;i<triangleSide;++i)
        {
            for(int j=0;j<(i<<1)+1;++j)
            {
                hexagonal[x+i][y+j] = status;
            }
        }
    }
    else
    {
        x += (triangleSide - 1);
        y += (triangleSide - 1) << 1;
        for(int i=0;i<triangleSide;++i)
        {
            for(int j=0;j<(i<<1)+1;++j)
            {
                hexagonal[x-i][y-j] = status;
            }
        }
    }
}

void printHexagonl()
{
    int spaceNumber;
    for(int i=1;i<=(hexagonalSide<<1);++i)
    {
        if(i<=hexagonalSide)
        {
            spaceNumber = (hexagonalSide - i) << 1;
        }
        else
        {
            spaceNumber = (i - hexagonalSide - 1) << 1;
        }
        while(spaceNumber--)
        {
            printf(" ");
        }
        for(int j=hexagonalWideStart[i];j<=hexagonalWideEnd[i];++j)
        {
            printf("%d ",hexagonal[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool findCutMethod(int x, int y, const int remainingSize)
{
    if(0 == remainingSize)
    {
        return true;
    }
    if(!isSizeAvailable[remainingSize])
    {
        return false;
    }
    if(y > hexagonalWideEnd[x])
    {
        return findCutMethod(x + 1, hexagonalWideStart[x + 1], remainingSize);
    }
    if(hexagonal[x][y])
    {
        for(;hexagonal[x][y] && y<=hexagonalWideEnd[x];++y);
        return findCutMethod(x, y, remainingSize);
    }
    for(int k=0;k<triangleTypeNumber;++k)
    {
        if(couldPlaceTriangle(x,y,triangleType[k]))
        {
            setTriangle(x,y,triangleType[k],true);
            if(findCutMethod(x, y + 1, remainingSize - triangleType[k] * triangleType[k]))
            {
                return true;
            }
            setTriangle(x,y,triangleType[k],false);
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int caseNumber;
    bool isCompletelyDivided;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        isCompletelyDivided = false;
        scanf("%d%d",&hexagonalSide,&triangleTypeNumber);
        for(int i=0;i<triangleTypeNumber;++i)
        {
            scanf("%d",&triangleType[i]);
        }
        if(isHexagonalSideDivisibleByTriangle())
        {
            isCompletelyDivided = true;
        }
        else
        {
            reduceTriangleTypeNumber();
            calculateAvailableSize();
            calculateHexagonalWide();
            memset(hexagonal, false, sizeof(hexagonal));
            if(!isSizeAvailable[hexagonalSide])
            {
                isCompletelyDivided = false;
            }
            else
            {
                isCompletelyDivided = findCutMethod(1, 1, hexagonalSide * hexagonalSide * 6);
            }
        }
        if(isCompletelyDivided)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

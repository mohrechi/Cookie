#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
    #define Stream_Debug
    #define Password_Test
    #define Decode_Test
#endif

static const int MAXN = 5000;
static const int directionX[] = {0, 0, 1, 1};
static const int directionY[] = {0, 1, 0, 1};

int n, leafNumber, maxDepth;
int encodeResult[MAXN];
bool isEncodeResult[MAXN];
int encodeImage[MAXN];
bool isEncodeImage[MAXN];
int password[MAXN];
int decodeImage[MAXN][MAXN];

inline const int min(const int &x, const int &y)
{
    return x<y?x:y;
}

void input()
{
    int leafIndex;
    scanf("%d%d",&n,&leafNumber);
    memset(isEncodeResult, false, sizeof(isEncodeImage));
    for(int i=0;i<leafNumber;++i)
    {
        scanf("%d",&leafIndex);
        isEncodeResult[leafIndex] = true;
        scanf("%d",&encodeResult[leafIndex]);
    }
    scanf("%d",&leafNumber);
    memset(isEncodeImage, false, sizeof(isEncodeImage));
    for(int i=0;i<leafNumber;++i)
    {
        scanf("%d",&leafIndex);
        isEncodeImage[leafIndex] = true;
        scanf("%d",&encodeImage[leafIndex]);
    }
    maxDepth = 0;
    int temp = n;
    while(temp>1)
    {
        ++maxDepth;
        temp /= 2;
    }
}

int decode(int node)
{
    if(isEncodeResult[node])
    {
        return encodeResult[node];
    }
    int leaf[4], sort[4];
    int minValue = 0x7FFFFFFF;
    for(int i=0;i<4;++i)
    {
        sort[i] = leaf[i] = decode(node * 4 + i + 1);
        minValue = min(minValue, leaf[i]);
    }
    for(int i=0;i<4;++i)
    {
        for(int j=i+1;j<4;++j)
        {
            if(sort[i] > sort[j])
            {
                sort[i] ^= sort[j];
                sort[j] ^= sort[i];
                sort[i] ^= sort[j];
            }
        }
    }
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            if(leaf[i] == sort[j])
            {
                password[node*4 + j + 1] = i + 1;
            }
        }
    }
    return minValue;
}

#ifdef Password_Test
void printPassword(int node, int depth)
{
    if(depth == maxDepth)
    {
        return;
    }
    printf("Node %d:",node);
    for(int i=0;i<4;++i)
    {
        printf(" %d",password[node*4 + i + 1]);
    }
    printf("\n");
    for(int i=0;i<4;++i)
    {
        printPassword(node*4+i+1, depth+1);
    }
}
#endif

void encode(int node, int width, int value, int x, int y, bool meet)
{
    #ifdef Decode_Test
        printf("%-4d%-4d%-4d%-4d: ", node,value,x,y);
        for(int i=0;i<width;++i)
        {
            printf("_");
        }
        printf("%d\n",node);
    #endif
    if(width == 0)
    {
        decodeImage[x][y] = value;
        return;
    }
    if(!isEncodeImage[node])
    {
        int temp;
        for(int i=0;i<4;++i)
        {
            if(meet)
            {
                temp = value;
            }
            else
            {
                temp = encodeImage[node*4 + password[node*4+i+1]];
            }
            encode(node*4 + password[node*4+i+1], width>>1, temp, x + directionX[i] * width , y + directionY[i] * width, meet);
        }
    }
    else
    {
        for(int i=0;i<4;++i)
        {
            encode(node*4+i+1, width>>1, encodeImage[node], x + directionX[i] * width , y + directionY[i] * width, true);
        }
    }
}

void output(int caseIndex)
{
    if(caseIndex > 1)
    {
        printf("\n");
    }
    printf("Case %d\n\n", caseIndex);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%4d",decodeImage[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    #ifdef Stream_Debug
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int caseNumber;
    scanf("%d",&caseNumber);
    for(int i=1;i<=caseNumber;++i)
    {
        input();
        decode(0);
        #ifdef Password_Test
        printf("Password: \n");
        printPassword(0,0);
        #endif
        encode(0, n>>1, encodeImage[0], 0, 0, false);
        output(i);
    }
    return 0;
}

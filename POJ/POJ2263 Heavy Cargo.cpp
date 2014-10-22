#include <cstdio>
#include <cstring>
//#define DEBUG
#ifdef DEBUG
    #define DEBUG_TRIE
    #define DEBUG_GRAPH
    #define DEBUG_RESULT
#endif
static const int MAXNODENUM     = 93; //Should be 6000
static const int MAXALPHANUM    = 53;
static const int MAXCITYNUM     = 139; //Should be 200
static const int TREEVALUEBIT   = 52;
static const int INVALIDNUM     = -1;

typedef struct TreeNode
{
    int next[MAXALPHANUM];
}TreeNode;

TreeNode nameTree[MAXNODENUM];
int currentNodeNumber;

void initialNameTree()
{
    for(int i=0;i<MAXNODENUM;++i)
    {
        for(int j=0;j<MAXALPHANUM;++j)
        {
            nameTree[i].next[j] = INVALIDNUM;
        }
    }
    currentNodeNumber = 0;
}

int transferCharacterToNumber(const char character)
{
    if(character >= 'A' && character <= 'Z')
    {
        return character - 'A';
    }
    return character - 'a' + 26;
}

void addNameToTree(TreeNode &treeNode, const char *name, const int value)
{
    if(*name)
    {
        int number = transferCharacterToNumber(*name);
        if(INVALIDNUM == treeNode.next[number])
        {
            treeNode.next[number] = ++currentNodeNumber;
        }
        addNameToTree(nameTree[treeNode.next[number]], name + 1, value);
    }
    else
    {
        treeNode.next[TREEVALUEBIT] = value;
    }
}

int findNameFromTree(TreeNode &treeNode, const char *name)
{
    if(*name)
    {
        int number = transferCharacterToNumber(*name);
        if(INVALIDNUM == treeNode.next[number])
        {
            return INVALIDNUM;
        }
        return findNameFromTree(nameTree[treeNode.next[number]], name + 1);
    }
    else
    {
        return treeNode.next[TREEVALUEBIT];
    }
}

#ifdef DEBUG_TRIE
char transferNumberToCharacter(int number)
{
    if(number >= 0 && number <= 25)
    {
        return number + 'A';
    }
    return number - 26 + 'a';
}

void printNameTree(const TreeNode &node, const int depth = 0)
{
    for(int i=0;i<TREEVALUEBIT;++i)
    {
        if(INVALIDNUM != node.next[i])
        {
            for(int j=0;j<depth;++j)
            {
                printf(" ");
            }
            printf("%c\n", transferNumberToCharacter(i));
            printNameTree(nameTree[node.next[i]], depth + 1);
        }
    }
}
#endif

int cityNumber, roadNumber;
int graph[MAXCITYNUM][MAXCITYNUM];
int startNumber, endNumber;

bool input()
{
    char startCityName[35], endCityName[35];
    int startCityNumber, endCityNumber, currentCityNumber, roadWeightLimit;
    scanf("%d%d",&cityNumber,&roadNumber);
    if(cityNumber || roadNumber)
    {
        initialNameTree();
        currentCityNumber = 0;
        memset(graph, 0, sizeof(graph));
        for(int i=0;i<roadNumber;++i)
        {
            scanf("%s%s%d", startCityName, endCityName, &roadWeightLimit);
            startCityNumber = findNameFromTree(nameTree[0], startCityName);
            endCityNumber = findNameFromTree(nameTree[0], endCityName);
            if(INVALIDNUM == startCityNumber)
            {
                addNameToTree(nameTree[0], startCityName, currentCityNumber);
                startCityNumber = currentCityNumber++;
            }
            if(INVALIDNUM == endCityNumber)
            {
                addNameToTree(nameTree[0], endCityName, currentCityNumber);
                endCityNumber = currentCityNumber++;
            }
            graph[startCityNumber][endCityNumber] = graph[endCityNumber][startCityNumber] = roadWeightLimit;
        }
        scanf("%s%s",startCityName, endCityName);
        startNumber = findNameFromTree(nameTree[0], startCityName);
        endNumber = findNameFromTree(nameTree[0], endCityName);
        return true;
    }
    return false;
}

#ifdef DEBUG_GRAPH
void printGraph()
{
    printf("Graph: \n");
    for(int i=0;i<cityNumber;++i)
    {
        for(int j=0;j<cityNumber;++j)
        {
            printf("%5d",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif

int max(const int x, const int y)
{
    return x>y?x:y;
}

int min(const int x, const int y)
{
    return x<y?x:y;
}

int maximum[MAXCITYNUM];
int queue[MAXCITYNUM], front, end;

void solve()
{
    memset(maximum, 0, sizeof(maximum));
    maximum[startNumber] = 0x7FFFFFF;
    front = 0, end = 1;
    queue[0] = startNumber;
    #ifdef DEBUG_RESULT
        printf("Start: %d  End: %d\n", startNumber, endNumber);
    #endif
    while(front < end)
    {
        for(int i=0;i<cityNumber;++i)
        {
            if(graph[queue[front]][i])
            {
                int origin = maximum[i];
                maximum[i] = max(maximum[i], min(maximum[queue[front]], graph[queue[front]][i]));
                if(origin < maximum[i])
                {
                    queue[end++] = i;
                }
            }
        }
        ++front;
        #ifdef DEBUG_RESULT
            for(int i=0;i<cityNumber;++i)
            {
                printf("%5d ", maximum[i]);
            }
            printf("\n");
        #endif
    }
}

void output()
{
    static int caseNumber = 0;
    printf("Scenario #%d\n", ++caseNumber);
    printf("%d tons\n\n", maximum[endNumber]);
}

int main(int argc, char *argv[])
{
    int caseNumber = 0;
    while(input())
    {
        #ifdef DEBUG_TRIE
            printNameTree(nameTree[0]);
        #endif
        #ifdef DEBUG_GRAPH
            printGraph();
        #endif
        solve();
        output();
    }
    return 0;
}

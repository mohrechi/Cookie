#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define DEBUG
const int MAXN = 25;

class NameSet
{
    public:
        NameSet()
        {
            this->totalNameNumber = 0;
        }
        void add(char *name)
        {
            strcpy(this->name[++this->totalNameNumber], name);
        }
        int find(char *name)
        {
            for(int i=1;i<=this->totalNameNumber;++i)
            {
                if(strcmp(this->name[i], name) == 0)
                {
                    return i;
                }
            }
            strcpy(this->name[++this->totalNameNumber], name);
            return this->totalNameNumber;
        }
        char* getNameByIndex(int index)
        {
            return this->name[index];
        }
    private:
        int totalNameNumber;
        char name[MAXN][MAXN];
}*criminalName, *criminalID;

class BiGraph
{
    public:
        BiGraph()
        {
        }
        void setMaxNumber(int number)
        {
            this->maxNumber = number;
        }
        void setPossiblility(bool graph[MAXN][MAXN])
        {
            memcpy(this->possibilityGraph, graph, sizeof(this->possibilityGraph));
        }
        void getMaximumMatch()
        {
            this->maximumMatch = 0;
            memset(this->link, 0, sizeof(this->link));
            for(int i=1;i<=this->maxNumber;++i)
            {
                memset(this->visited, false, sizeof(this->visited));
                if(this->findMatch(i))
                {
                    ++this->maximumMatch;
                }
            }
        }
        int getMaximumMatchNumber() const
        {
            return this->maximumMatch;
        }
        int getMatchByIndex(int index) const
        {
            return this->link[index];
        }
        void setMatchByIndex(int index, int number)
        {
            this->link[index] = number;
        }
    private:
        int maxNumber;
        int maximumMatch;
        bool possibilityGraph[MAXN][MAXN];
        bool visited[MAXN];
        int link[MAXN];
        bool findMatch(int index)
        {
            for(int i=1;i<=this->maxNumber;++i)
            {
                if(!this->visited[i] && this->possibilityGraph[index][i])
                {
                    this->visited[i] = true;
                    if(this->link[i] == 0 || this->findMatch(link[i]))
                    {
                        this->link[i] = index;
                        return true;
                    }
                }
            }
            return false;
        }
}*mainGraph, *assistGraph;

int criminalNumber;
bool possibilityGraph[MAXN][MAXN];
bool isCriminalIn[MAXN];
bool firstMessage[MAXN];

void input()
{
    criminalName = new NameSet();
    criminalID = new NameSet();
    scanf("%d",&criminalNumber);
    char tempName[MAXN];
    char tempOperation[MAXN];
    for(int i=1;i<=criminalNumber;++i)
    {
        scanf("%s",tempName);
        criminalID->add(tempName);
    }
    memset(firstMessage, true, sizeof(firstMessage));
    memset(possibilityGraph, true, sizeof(possibilityGraph));
    memset(isCriminalIn, false, sizeof(isCriminalIn));
    while(scanf("%s",tempOperation), *tempOperation != 'Q')
    {
        scanf("%s",tempName);
        if(*tempOperation != 'M')
        {
            if(*tempOperation == 'E')
            {
                isCriminalIn[criminalName->find(tempName)] = true;
            }
            else
            {
                isCriminalIn[criminalName->find(tempName)] = false;
            }
            #ifdef DEBUG
                printf("Room Status: ");
                for(int i=1;i<=criminalNumber;++i)
                {
                    printf("%d ",isCriminalIn[i]);
                }
                printf("\n");
            #endif
        }
        else
        {
            int tempNumber = criminalID->find(tempName);
            /*if(firstMessage[tempNumber])
            {
                for(int i=1;i<=criminalNumber;++i)
                {
                    possibilityGraph[tempNumber][i] = isCriminalIn[i];
                }
                firstMessage[tempNumber] = false;
            }
            else
            {
                for(int i=1;i<=criminalNumber;++i)
                {
                    if(!isCriminalIn[i])
                    {
                        possibilityGraph[tempNumber][i] = false;
                    }
                }
            }*/
            for(int i=1;i<=criminalNumber;++i)
            {
                if(!isCriminalIn[i])
                {
                    possibilityGraph[tempNumber][i] = false;
                }
            }
            #ifdef DEBUG
                printf("Possibility Graph (ID - name): \n");
                for(int i=1;i<=criminalNumber;++i)
                {
                    for(int j=1;j<=criminalNumber;++j)
                    {
                        printf("%d ",possibilityGraph[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            #endif
        }
    }
}

void reversePossibility()
{
    for(int i=1;i<=criminalNumber;++i)
    {
        for(int j=i+1;j<=criminalNumber;++j)
        {
            possibilityGraph[i][j] ^= possibilityGraph[j][i];
            possibilityGraph[j][i] ^= possibilityGraph[i][j];
            possibilityGraph[i][j] ^= possibilityGraph[j][i];
        }
    }
    #ifdef DEBUG
        printf("Possibility Graph (name - ID): \n");
        for(int i=1;i<=criminalNumber;++i)
        {
            for(int j=1;j<=criminalNumber;++j)
            {
                 printf("%d ",possibilityGraph[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    #endif
}

void solve()
{
    //reversePossibility();
    mainGraph = new BiGraph();
    mainGraph->setMaxNumber(criminalNumber);
    mainGraph->setPossiblility(possibilityGraph);
    mainGraph->getMaximumMatch();
    assistGraph = new BiGraph();
    assistGraph->setMaxNumber(criminalNumber);
    #ifdef DEBUG
        printf("Maximum Match: %d\n",mainGraph->getMaximumMatchNumber());
    #endif
    for(int i=1;i<=criminalNumber;++i)
    {
        if(mainGraph->getMatchByIndex(i) != 0)
        {
            possibilityGraph[mainGraph->getMatchByIndex(i)][i] = false;
            assistGraph->setPossiblility(possibilityGraph);
            assistGraph->getMaximumMatch();
            possibilityGraph[mainGraph->getMatchByIndex(i)][i] = true;
            if(mainGraph->getMaximumMatchNumber() == assistGraph->getMaximumMatchNumber())
            {
                mainGraph->setMatchByIndex(i, 0);
            }
        }
        #ifdef DEBUG
            printf("%d ",assistGraph->getMaximumMatchNumber());
        #endif
    }
    #ifdef DEBUG
        printf("\n");
    #endif
}

struct Match
{
    char name[MAXN];
    char ID[MAXN];
    void print()
    {
        printf("%s:%s\n",name,ID);
    }
}result[MAXN + 1];

void output()
{
    for(int i=1;i<=criminalNumber;++i)
    {
        strcpy(result[i].name, criminalName->getNameByIndex(i));
        if(mainGraph->getMatchByIndex(i) == 0)
        {
            strcpy(result[i].ID, "???");
        }
        else
        {
            strcpy(result[i].ID, criminalID->getNameByIndex(mainGraph->getMatchByIndex(i)));
        }
    }
    for(int i=1;i<=criminalNumber;++i)
    {
        for(int j=i+1;j<=criminalNumber;++j)
        {
            if(strcmp(result[i].name, result[j].name)>0)
            {
                result[MAXN] = result[i];
                result[i] = result[j];
                result[j] = result[MAXN];
            }
        }
    }
    for(int i=1;i<=criminalNumber;++i)
    {
        result[i].print();
    }
}

int main(int argc, char *argv[])
{
    input();
    solve();
    output();
    return 0;
}

#include <cstdio>
using namespace std;

//#define DEBUG

static const int MAX_STUDENT = 160;
static const int MAX_REGION = 60;

int studentNumber;
int studentsDream[MAX_STUDENT][MAX_REGION];
int studentsBelong[MAX_STUDENT];
int studentsScore[MAX_STUDENT];
int studentsResult[MAX_STUDENT];
int studentsStack[MAX_STUDENT];
int studentsStackTop;
int studentsDisappoint[MAX_STUDENT];
int regionNumber;
int regionsName[MAX_REGION];
int regionsNeed[MAX_REGION];
int regionsJudge[MAX_REGION][MAX_STUDENT];
int regionsResult[MAX_REGION][MAX_STUDENT];

void input()
{
    scanf("%d%d",&studentNumber,&regionNumber);
    for(int studentIndex=1;studentIndex<=studentNumber;++studentIndex)
    {
        scanf("%d%d%d",&studentsBelong[studentIndex],&studentsScore[studentIndex],&studentsDream[studentIndex][0]);
        for(int dreamIndex=1;dreamIndex<=studentsDream[studentIndex][0];++dreamIndex)
        {
            scanf("%d",&studentsDream[studentIndex][dreamIndex]);
        }
        studentsScore[studentIndex] *= 10;
    }
    for(int regionIndex=1;regionIndex<=regionNumber;++regionIndex)
    {
        scanf("%d%d",&regionsName[regionIndex],&regionsNeed[regionIndex]);
    }
}

inline void clearStudentsStack()
{
    studentsStackTop = 0;
}

inline void pushStudentsStack(int number)
{
    studentsStack[studentsStackTop++] = number;
}

inline int popStudentsStack()
{
    return studentsStack[--studentsStackTop];
}

inline int topStudentsStack()
{
    return studentsStack[studentsStackTop - 1];
}

inline bool isEmptyStudentsStack()
{
    return studentsStackTop == 0;
}

inline bool notEmptyStudentsStack()
{
    return studentsStackTop > 0;
}

void initialStudentsChoice()
{
    clearStudentsStack();
    for(int studentIndex=studentNumber;studentIndex>0;--studentIndex)
    {
        studentsDisappoint[studentIndex] = 1;
        pushStudentsStack(studentIndex);
    }
}

void initialRegionsJudge()
{
    for(int regionIndex = 1;regionIndex <= regionNumber;++regionIndex)
    {
        for(int studentIndex = 1;studentIndex <= studentNumber;++studentIndex)
        {
            if(studentsBelong[studentIndex] == regionIndex)
            {
                regionsJudge[regionIndex][studentIndex] = studentsScore[studentIndex];
            }
            else
            {
                regionsJudge[regionIndex][studentIndex] = studentsScore[studentIndex] * 7 / 10;
            }
        }
        regionsResult[regionIndex][0] = 0;
    }
}

void initial()
{
    initialStudentsChoice();
    initialRegionsJudge();
}

bool apply(int studentIndex, int regionIndex)
{
    #ifdef DEBUG
        printf("Student %d apply for Region %d: ",studentIndex,regionIndex);
    #endif
    if(regionsNeed[regionIndex] == 0)
    {
        return false;
    }
    if(regionsResult[regionIndex][0] < regionsNeed[regionIndex])
    {
        regionsResult[regionIndex][++regionsResult[regionIndex][0]] = studentIndex;
        studentsResult[studentIndex] = regionIndex;
        #ifdef DEBUG
            printf("Did not recruit enough, succeed. %d/%d\n",regionsResult[regionIndex][0],regionsNeed[regionIndex]);
        #endif
        return true;
    }
    else
    {
        int poorResultIndex = 1;
        for(int resultIndex = 2;resultIndex <= regionsResult[regionIndex][0];++resultIndex)
        {
            if(regionsJudge[regionIndex][regionsResult[regionIndex][resultIndex]] < regionsJudge[regionIndex][regionsResult[regionIndex][poorResultIndex]])
            {
                poorResultIndex = resultIndex;
            }
        }
        if(regionsJudge[regionIndex][studentIndex] > regionsJudge[regionIndex][regionsResult[regionIndex][poorResultIndex]])
        {
            pushStudentsStack(regionsResult[regionIndex][poorResultIndex]);
            studentsDisappoint[regionsResult[regionIndex][poorResultIndex]] ++;
            #ifdef DEBUG
                printf("Better than student %d, succeed.\n",regionsResult[regionIndex][poorResultIndex]);
            #endif
            regionsResult[regionIndex][poorResultIndex] = studentIndex;
            studentsResult[studentIndex] = regionIndex;
            return true;
        }
        else if(regionsJudge[regionIndex][studentIndex] == regionsJudge[regionIndex][regionsResult[regionIndex][poorResultIndex]])
        {
            if(studentsDisappoint[studentIndex] < studentsDisappoint[regionsResult[regionIndex][poorResultIndex]])
            {
                pushStudentsStack(regionsResult[regionIndex][poorResultIndex]);
                studentsDisappoint[regionsResult[regionIndex][poorResultIndex]] ++;
                #ifdef DEBUG
                    printf("More desire than student %d, succeed.\n",regionsResult[regionIndex][poorResultIndex]);
                #endif
                regionsResult[regionIndex][poorResultIndex] = studentIndex;
                studentsResult[studentIndex] = regionIndex;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            #ifdef DEBUG
                printf("Not good enough, failed.\n");
            #endif
            return false;
        }
    }
}

void examination()
{
    while(notEmptyStudentsStack())
    {
        int studentIndex = popStudentsStack();
        for(;studentsDisappoint[studentIndex]<=studentsDream[studentIndex][0];++studentsDisappoint[studentIndex])
        {
            if(apply(studentIndex, studentsDream[studentIndex][studentsDisappoint[studentIndex]]))
            {
                break;
            }
        }
    }
}

void output(int caseIndex)
{
    if(caseIndex)
    {
        printf("\n");
    }
    for(int studentIndex=1;studentIndex<=studentNumber;++studentIndex)
    {
        if(studentsDisappoint[studentIndex] <= studentsDream[studentIndex][0])
        {
            printf("%d\n",studentsResult[studentIndex]);
        }
        else
        {
            printf("not accepted\n");
        }
    }
}

int main(int argc, char* argv[])
{
    int caseNumber;
    scanf("%d",&caseNumber);
    for(int caseIndex = 0;caseIndex < caseNumber;++caseIndex)
    {
        input();
        initial();
        examination();
        output(caseIndex);
    }
    return 0;
}

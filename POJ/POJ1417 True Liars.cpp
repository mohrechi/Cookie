#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
//#define DEBUG
#define MAXN 605
#define MAXM 1005

struct Relation
{
    int firstPerson;
    int secondPerson;
    bool group;
};

class MSet
{
public:
    void clear();
    void add(int x);
    int getNumber();
    int getArray(int x);
    void output();

private:
    int number;
    int array[MAXN];
};

class Group
{
public:
    void initial();
    void addRoot(int head);
    void add(bool relation);
    int getSingleGroupNumber(int head, bool relation);
    int getRootNumber();
    int getGroup(int x);

private:
    MSet root;
    int array[MAXN][2];
};

class UFSet
{
public:
    void initial();
    int find(int x);
    void combine(int x, int y, bool parity);
    int getParity(int x);

private:
    int father[MAXN];
    bool parity[MAXN];
};

class Solve
{
public:
    Solve();
    bool input();
    void solve();
    void setDebug();
    void output();

private:
    UFSet *set;
    MSet *answer;
    Group *group;
    Relation relation;
    int relationNumber;
    int divineNumber;
    int devilishNumber;
    int totalNumber;
    int dp[MAXN][MAXN];
    int prev[MAXN][MAXN];
    bool solvable;

    void makeGroup();
};

void UFSet::initial()
{
    for(int i=0;i<MAXN;++i)
    {
        father[i] = i;
        parity[i] = false;
    }
}

int UFSet::getParity(int x)
{
    return parity[x];
}

int UFSet::find(int x)
{
    if(father[x] == x)
    {
        return x;
    }
    int temp = father[x];
    father[x] = find(father[x]);
    parity[x] ^= parity[temp];
    return father[x];
}

void UFSet::combine(int x, int y, bool relation)
{
    int fatherX = find(x);
    int fatherY = find(y);
    if(fatherX < fatherY)
    {
        father[fatherY] = fatherX;
        parity[fatherY] = relation ^ parity[x] ^ parity[y];
    }
    else if(fatherX > fatherY)
    {
        father[fatherX] = fatherY;
        parity[fatherX] = relation ^ parity[x] ^ parity[y];
    }
}

Solve::Solve()
{
    set = new UFSet();
    answer = new MSet();
    group = new Group();
}

void Solve::setDebug()
{
    #ifdef DEBUG
    printf("\nUnion-Finding Set Debug: \n");
    for(int i=1;i<=totalNumber;++i)
    {
        printf("\tNode %d: Father %d Parity: %d\n", i, set->find(i), set->getParity(i));
    }
    printf("End Union-Finding Set Debug\n\n");
    #endif
}

void Solve::solve()
{
    setDebug();
    makeGroup();
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int x,y;
    for(int i=0;i<group->getRootNumber();++i)
    {
        for(int j=divineNumber;j>=0;--j)
        {
            for(int k=devilishNumber;k>=0;--k)
            {
                x = j - group->getSingleGroupNumber(i, false);
                y = k - group->getSingleGroupNumber(i, true);
                if(x >= 0 and y>=0 and dp[x][y])
                {
                    dp[j][k] += dp[x][y];
                }
                x = j - group->getSingleGroupNumber(i, true);
                y = k - group->getSingleGroupNumber(i, false);
                if(x >= 0 and y>=0 and dp[x][y])
                {
                    dp[j][k] += dp[x][y];
                }
            }
        }
    }
    if(dp[divineNumber][devilishNumber] != 1)
    {
        solvable = false;
        return;
    }
    memset(dp, 0, sizeof(dp));
    memset(prev, 0 ,sizeof(prev));
    dp[0][0] = 1;
    for(int i=0;i<group->getRootNumber();++i)
    {
        for(int j=divineNumber;j>=0;--j)
        {
            for(int k=devilishNumber;k>=0;--k)
            {
                if(dp[j][k])
                {
                    continue;
                }
                x = j - group->getSingleGroupNumber(i, false);
                y = k - group->getSingleGroupNumber(i, true);
                if(x >= 0 and y>=0 and dp[x][y])
                {
                    dp[j][k] += dp[x][y];
                    prev[j][k] = 0;
                }
                x = j - group->getSingleGroupNumber(i, true);
                y = k - group->getSingleGroupNumber(i, false);
                if(x >= 0 and y>=0 and dp[x][y])
                {
                    dp[j][k] += dp[x][y];
                    prev[j][k] = 1;
                }
            }
        }
    }
    answer->clear();
    x = divineNumber;
    y = devilishNumber;
    for(int i=group->getRootNumber() - 1;i>=0;--i)
    {
        for(int j=1;j<=totalNumber;++j)
        {
            if(set->find(j) == group->getGroup(i))
            {
                if(set->getParity(j) == prev[x][y])
                {
                    answer->add(j);
                }
            }
        }
        if(prev[x][y])
        {
            x -= group->getSingleGroupNumber(i, true);
            y -= group->getSingleGroupNumber(i, false);
        }
        else
        {
            x -= group->getSingleGroupNumber(i, false);
            y -= group->getSingleGroupNumber(i, true);
        }
    }
}

bool Solve::input()
{
    scanf("%d%d%d",&relationNumber,&divineNumber,&devilishNumber);
    if(relationNumber || divineNumber || devilishNumber)
    {
        solvable = not (divineNumber == devilishNumber);
        set->initial();
        char s[10];
        for(int i=0;i<relationNumber;++i)
        {
            scanf("%d%d%s",&relation.firstPerson,&relation.secondPerson,s);
            relation.group = *s == 'n';
            set->combine(relation.firstPerson, relation.secondPerson, relation.group);
        }
        totalNumber = divineNumber + devilishNumber;
        return true;
    }
    return false;
}

void Solve::output()
{
    if(solvable)
    {
        answer->output();
    }
    else
    {
        printf("no\n");
    }
}

void Solve::makeGroup()
{
    group->initial();
    for(int i=1;i<=totalNumber;++i)
    {
        if(set->find(i) == i)
        {
            group->addRoot(i);
            for(int j=1;j<=totalNumber;++j)
            {
                if(set->find(j) == i)
                {
                    group->add(set->getParity(j));
                }
            }
        }
    }
}

void MSet::clear()
{
    number = 0;
}

void MSet::add(int x)
{
    array[number++] = x;
}

int MSet::getNumber()
{
    return number;
}

int MSet::getArray(int x)
{
    return array[x];
}

void MSet::output()
{
    sort(array, array + number);
    for(int i=0;i<number;i++)
    {
        printf("%d\n",array[i]);
    }
    printf("end\n");
}

void Group::initial()
{
    memset(array, 0, sizeof(array));
    root.clear();
}

int Group::getGroup(int x)
{
    return root.getArray(x);
}

void Group::addRoot(int head)
{
    root.add(head);
}

int Group::getRootNumber()
{
    return root.getNumber();
}

void Group::add(bool relation)
{
    ++array[root.getNumber() - 1][relation];
}

int Group::getSingleGroupNumber(int head, bool relation)
{
    return array[head][relation];
}

int main(int argc, char *argv[])
{
    Solve *solve = new Solve();
    while(solve->input())
    {
        solve->solve();
        solve->output();
    }
    return 0;
}

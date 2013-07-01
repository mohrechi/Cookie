#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
static const int MAXN = 250;

double totalLength;
int houseNumber, pathNumber;
string houseName[MAXN];
struct Path
{
    int s, t;
    double length;
    bool operator < (const Path &p) const
    {
        return length < p.length;
    }
}path[MAXN * MAXN];

int findNameIndex(string name)
{
    int left = 0, right = houseNumber - 1, mid;
    while(true)
    {
        mid = (left + right) >> 1;
        if(houseName[mid] > name)
        {
            right = mid - 1;
        }
        else if(houseName[mid] < name)
        {
            left = mid + 1;
        }
        else
        {
            break;
        }
    }
    return mid;
}

void input()
{
    string name1, name2;
    scanf("%lf",&totalLength);
    scanf("%d",&houseNumber);
    for(int i=0;i<houseNumber;++i)
    {
        cin>>houseName[i];
    }
    sort(houseName, houseName + houseNumber);
    scanf("%d",&pathNumber);
    for(int i=0;i<pathNumber;++i)
    {
        cin>>name1>>name2;
        path[i].s = findNameIndex(name1);
        path[i].t = findNameIndex(name2);
        scanf("%lf",&path[i].length);
    }
}

int father[MAXN];
double minimumLength;

void initial()
{
    for(int i=0;i<houseNumber;++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = father[x];
    y = father[y];
    father[x] = y;
}

void solve()
{
    sort(path, path + pathNumber);
    minimumLength = 0.0;
    initial();
    int count = 0;
    for(int i=0;i<pathNumber;++i)
    {
        if(find(path[i].s) != find(path[i].t))
        {
            minimumLength += path[i].length;
            if(++count == houseNumber - 1)
            {
                break;
            }
            combine(path[i].s, path[i].t);
        }
    }
}

void output()
{
    if(minimumLength > totalLength)
    {
        printf("Not enough cable\n");
    }
    else
    {
        printf("Need %.1lf miles of cable", minimumLength);
    }
}

int main(int argc, char *argv[])
{
    input();
    solve();
    output();
    return 0;
}

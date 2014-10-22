#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXM = 51;
const int MAXK = 1001;

bool isEng[MAXN][MAXM];

struct Student
{
    int a, b;
    char s[10];
    bool isEng;
    inline void input()
    {
        scanf("%d%d%s", &a, &b, s);
    }
    inline void output()
    {
        printf("%d %d %s\n", a, b, s);
    }
} stu[MAXK];

bool operator < (const Student &a, const Student &b)
{
    if(a.a == b.a)
    {
        if(a.isEng == b.isEng)
        {
            if(a.b == b.b)
            {
                return strcmp(a.s, b.s) > 0;
            }
            return a.b < b.b;
        }
        return a.isEng < b.isEng;
    }
    return a.a < b.a;
}

int main()
{
    int n, m, k, t;
    scanf("%d", &n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d", &m);
        while(scanf("%d", &t), t)
        {
            isEng[i][t] = true;
        }
    }
    scanf("%d", &k);
    for(int i=0;i<k;++i)
    {
        stu[i].input();
        stu[i].isEng = !isEng[stu[i].a][stu[i].b];
    }
    sort(stu, stu + k);
    for(int i=0;i<k;++i)
    {
        stu[i].output();
    }
    return 0;
}

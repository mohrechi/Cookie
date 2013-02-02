#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

char s[MAXN];
int num[MAXN];
bool visit[MAXN];

struct Node
{
    int value, index, error;

    Node(int _value, int _index, int _error)
    {
        value = _value;
        index = _index;
        error = _error;
    }

    bool operator < (const Node &node) const
    {
        if(value == node.value)
        {
            return index < node.index;
        }
        return value > node.value;
    }
} ;

int main()
{
    int n, k;
    int countStar;
    int countA, totalA;
    int cas = 0;
    while(~scanf("%d", &k))
    {
        scanf("%s", s);
        countStar = 0;
        countA = 0;
        int m = 0;
        for(int i=0;s[i];++i)
        {
            if(s[i] == 'A')
            {
                ++ countA;
                int count = 1;
                while(s[i+1] == 'A')
                {
                    ++ i;
                    ++ count;
                }
                s[m++] = count;

            }
            else if(s[i] == '*')
            {
                ++ countStar;
                s[m++] = '*';
            }
        }
        if(countStar < k)
        {
            printf("Xiang less\n");
        }
        else
        {
            totalA = 0;
            n = 0;
            s[m] = 0;
            for(int i=0;i<m;++i)
            {
                if(s[i] == '*')
                {
                    int count = 1;
                    while(s[i+1] == '*')
                    {
                        ++ i;
                        ++ count;
                    }
                    num[n] = count;
                    s[n++] = '*';
                }
                else
                {
                    totalA += s[i];
                    num[n] = s[i];
                    s[n++] = 'A';
                }
            }
            s[n] = 0;
            int expNum = countStar - k;
            int nodeNumber = 0;
            set<Node> finalSet;
            set<Node> bombSet;
            bool flag = false;
            int count1 = 0, count2 = 0;
            for(int i=n-1;i>=0;--i)
            {
                if(s[i] == '*')
                {
                    count1 += num[i];
                    if(count1 - count2 > k)
                    {
                        flag = true;
                        break;
                    }
                    int count = 0;
                    set<Node>::iterator it = bombSet.begin();
                    while(it != bombSet.end() && count < countStar)
                    {
                        ++ count;
                        finalSet.insert(*it);
                        ++ it;
                    }
                    bombSet.clear();
                    countStar -= num[i];
                }
                else
                {
                    ++ count2;
                    bombSet.insert(Node(num[i], i, countStar));
                }
            }
            if(flag || finalSet.size() < expNum)
            {
                printf("Xiang more\n");
            }
            else
            {
                memset(visit, false, sizeof(visit));
                int count = 1;
                for(set<Node>::iterator it=finalSet.begin();it!=finalSet.end() && count <= expNum;++it)
                {
                    for(int j=it->error;j>=1;--j)
                    {
                        if(!visit[j])
                        {
                            visit[j] = true;
                            ++ count;
                            totalA -= it->value;
                            break;
                        }
                    }
                }
                printf("%d\n", totalA);
            }
        }
    }
    return 0;
}

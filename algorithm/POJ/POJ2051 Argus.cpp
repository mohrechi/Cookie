#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int index, period, time;
    bool operator < (const Node &node) const
    {
        if(time == node.time)
        {
            return index > node.index;
        }
        return time > node.time;
    }
};

int main(int argc, char *argv[])
{
    char s[10];
    int id,pe,k;
    Node temp;
    priority_queue<Node> heap;
    while(scanf("%s",s),*s!='#')
    {
        scanf("%d%d",&id,&pe);
        temp.index = id;
        temp.period = pe;
        temp.time = pe;
        heap.push(temp);
    }
    scanf("%d",&k);
    while(k--)
    {
        temp = heap.top();
        heap.pop();
        temp.time += temp.period;
        heap.push(temp);
        printf("%d\n",temp.index);
    }
    return 0;
}

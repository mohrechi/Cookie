#include <cstdio>
#include <cstring>
static const int MAXN = 10005;
bool visited[MAXN];

int main(int argc, char *argv[])
{
    int number, range, count=0, answer = 1, id;
    scanf("%d%d",&number,&range);
    for(int i=0;i<number;++i)
    {
        scanf("%d",&id);
        if(!visited[id])
        {
            ++count;
            visited[id] = true;
        }
        if(count == range)
        {
            count = 0;
            ++answer;
            memset(visited, false, sizeof(visited));
        }
    }
    printf("%d\n",answer);
    return 0;
}

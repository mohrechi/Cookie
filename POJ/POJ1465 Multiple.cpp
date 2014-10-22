#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 5005
#define MAXM 10
struct Node
{
    int digit;
    int remainder;
    Node *pre;
}queue[MAXN];

void output(Node node)
{
    if(node.pre)
    {
        output(*node.pre);
        printf("%d",node.digit);
    }
}

void bfs(int n, int m, int *digit)
{
    bool hash[MAXN];
    int front=0, rear=1;
    memset(hash, false, sizeof(hash));
    queue[0].digit = 0;
    queue[0].remainder = 0;
    queue[0].pre = NULL;
    Node *first = &queue[0];
    while(front<rear)
    {
        Node now,current = queue[front];
        now.pre = &queue[front];
        for(int i=0;i<m;i++)
        {
            int r = ((10 * current.remainder) + digit[i]) % n;
            if(!hash[r] && (now.pre != first || digit[i] > 0))
            {
                hash[r] = true;
                now.remainder = r;
                now.digit = digit[i];
                queue[rear++] = now;
                if(now.remainder == 0)
                {
                    output(now);
                    printf("\n");
                    return;
                }
            }
        }
        front++;
    }
    printf("0\n");
}

int main(int argc, char *argv[])
{
	int n,m,digit[MAXM];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
	    for(int i=0;i<m;i++)
	    {
	        scanf("%d",&digit[i]);
	    }
	    if(!n)
	    {
	        printf("0\n");
	    }
	    else
	    {
	        sort(digit, digit+m);
            bfs(n,m,digit);
	    }
	}
	return 0;
}

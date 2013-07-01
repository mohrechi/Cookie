#include <stdio.h>
#include <string.h>
#include <memory.h>

struct Voter
{
    int like, dislike;
}cat[505],dog[505];

int totalCatNumber;
int totalDogNumber;
int voterNumber;
int catNumber;
int dogNumber;
int match[505];
bool visit[505];
bool graph[505][505];

int make(char s[])
{
    int value = 0;
    for(int i=0;s[i];i++)
    {
        value = value * 200 + s[i];
    }
    return value;
}

bool find(int u)
{
    for(int i=0;i<dogNumber;i++)
    {
        if(graph[u][i] && !visit[i])
        {
            visit[i] = true;
            if(match[i] == -1 || find(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

int get()
{
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i=0;i<catNumber;i++)
    {
        memset(visit, false, sizeof(visit));
        if(find(i))
        {
            ans ++;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
	int t;
	char s1[10],s2[10];
	scanf("%d",&t);
	while(t--)
	{
	    catNumber = 0;
	    dogNumber = 0;
	    scanf("%d%d%d",&totalCatNumber, &totalDogNumber, &voterNumber);
	    for(int i=0;i<voterNumber;i++)
	    {
	        scanf("%s%s",s1,s2);
	        if(s1[0]=='C')
	        {
	            cat[catNumber].like = make(s1 + 1);
	            cat[catNumber++].dislike = make(s2 + 1);
	        }
	        else
	        {
	            dog[dogNumber].like = make(s1 + 1);
	            dog[dogNumber++].dislike = make(s2 + 1);
	        }
	    }
	    memset(graph, false, sizeof(graph));
	    for(int i=0;i<catNumber;i++)
	    {
	        for(int j=0;j<dogNumber;j++)
	        {
	            if(cat[i].like == dog[j].dislike || cat[i].dislike == dog[j].like)
	            {
	                graph[i][j] = true;
	            }
	        }
	    }
	    printf("%d\n",voterNumber - get());
	}
	return 0;
}

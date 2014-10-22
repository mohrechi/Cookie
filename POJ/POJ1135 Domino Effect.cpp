#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
#define MAXN 505
#define INF 1000000000

int dominoNumber, connectNumber;
int graph[MAXN][MAXN];
int subGraph[MAXN][MAXN];

int main(int argc, char *argv[])
{
    int systemNumber = 0;
    while(scanf("%d%d",&dominoNumber,&connectNumber), dominoNumber or connectNumber)
    {
        for(int i=1;i<=dominoNumber;++i)
        {
            for(int j=1;j<=dominoNumber;++j)
            {
                graph[i][j] = INF;
                subGraph[i][j] = INF;
            }
        }
        int from, to, time;
        for(int i=0;i<connectNumber;++i)
        {
            scanf("%d%d%d",&from,&to,&time);
            graph[from][to] = graph[to][from] = min(graph[from][to], time);
            subGraph[from][to] = subGraph[to][from] = min(subGraph[from][to], time);
        }
        for(int k=1;k<=dominoNumber;++k)
        {
            graph[k][k] = 0;
            for(int i=1;i<=dominoNumber;++i)
            {
                for(int j=1;j<=dominoNumber;++j)
                {
                    if(graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        int maxTime = 0;
        int maxDomino = 1;
        for(int i=2;i<=dominoNumber;i++)
        {
            if(graph[1][i] > maxTime)
            {
                maxTime = graph[1][i];
                maxDomino = i;
            }
        }
        double maxSubTime = 0.0;
        int mateDomino = 0;
        for(int i=1;i<=dominoNumber;++i)
        {
            if(subGraph[maxDomino][i]!=INF)
            {
                if(subGraph[maxDomino][i] >= graph[1][maxDomino] - graph[1][i])
                {
                    double temp = (subGraph[maxDomino][i] - graph[1][maxDomino] + graph[1][i]) * 0.5;
                    if(temp > maxSubTime)
                    {
                        maxSubTime = temp;
                        mateDomino = i;
                    }
                }
            }
        }
        printf("System #%d\n", ++systemNumber);
        if(mateDomino)
        {
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n",maxTime + maxSubTime, min(maxDomino, mateDomino), max(maxDomino, mateDomino));
        }
        else
        {
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n",(double)maxTime, maxDomino);
        }
        printf("\n");
    }
    return 0;
}

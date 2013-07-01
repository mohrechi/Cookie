#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
#define MAXN 55
#define INF 1<<30;

int maxSum[MAXN][MAXN],minSum[MAXN][MAXN],maxScore;
int n,vertex[MAXN],edge[MAXN];
int tempVertex[MAXN], tempEdge[MAXN];
int answer[MAXN],answerTop;

void input()
{
    char s[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",s,&vertex[i]);
        if(*s=='t')
        {
            edge[i] = 0;
        }
        else
        {
            edge[i] = 1;
        }
    }
    edge[n] = edge[0];
}

long long get(int breakPoint)
{
    int b=0;
    for(int i=breakPoint;i<n;i++)
    {
        tempVertex[b] = vertex[i];
        tempEdge[b++] = edge[i+1];
    }
    for(int i=0;i<breakPoint;i++)
    {
        tempVertex[b] = vertex[i];
        tempEdge[b++] = edge[i+1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            maxSum[i][j] = -INF;
            minSum[i][j] = INF;
        }
        minSum[i][i] = maxSum[i][i] = tempVertex[i];
    }
    for(int len=1;len<n;len++)
    {
        for(int i=0;i+len<n;i++)
        {
            int j=i+len;
            for(int k=i;k<j;k++)
            {
                if(tempEdge[k]==0)
                {
                    maxSum[i][j] = max(maxSum[i][j], maxSum[i][k] + maxSum[k+1][j]);
                    minSum[i][j] = min(minSum[i][j], minSum[i][k] + minSum[k+1][j]);
                }
                else
                {
                    maxSum[i][j] = max(maxSum[i][j], minSum[i][k] * minSum[k+1][j]);
                    maxSum[i][j] = max(maxSum[i][j], minSum[i][k] * maxSum[k+1][j]);
                    maxSum[i][j] = max(maxSum[i][j], maxSum[i][k] * minSum[k+1][j]);
                    maxSum[i][j] = max(maxSum[i][j], maxSum[i][k] * maxSum[k+1][j]);
                    minSum[i][j] = min(minSum[i][j], minSum[i][k] * minSum[k+1][j]);
                    minSum[i][j] = min(minSum[i][j], minSum[i][k] * maxSum[k+1][j]);
                    minSum[i][j] = min(minSum[i][j], maxSum[i][k] * minSum[k+1][j]);
                    minSum[i][j] = min(minSum[i][j], maxSum[i][k] * maxSum[k+1][j]);
                }
            }
        }
    }
    return maxSum[0][n-1];
}

void output()
{
    printf("%d\n",maxScore);
    printf("%d",answer[0]);
    for(int i=1;i<answerTop;i++)
    {
        printf(" %d",answer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    input();
    answerTop = 0;
    maxScore = - INF;
    for(int i=0;i<n;i++)
    {
        long long temp = get(i);
        if(temp > maxScore)
        {
            maxScore = temp;
            answer[0] = i + 1;
            answerTop = 1;
        }
        else if (temp == maxScore)
        {
            answer[answerTop++] = i + 1;
        }
    }
    output();
    return 0;
}

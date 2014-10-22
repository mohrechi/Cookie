#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
#define MAXN 26
#define INF 1000000000

int graph[MAXN][MAXN];
int degree[MAXN];

int main(int argc, char *argv[])
{
    string s;
    while(cin>>s)
    {
        for(int i=0;i<MAXN;++i)
        {
            for(int j=0;j<MAXN;++j)
            {
                graph[i][j] = INF;
            }
            graph[i][i] = 0;
            degree[i] = 0;
        }
        int sum = 0;
        while(s!="deadend")
        {
            int a = s[0] - 'a';
            int b = s[s.length()-1] - 'a';
            ++degree[a];
            ++degree[b];
            graph[a][b] = graph[b][a] = s.length();
            sum += s.length();
            cin >> s;
        }
        for(int k=0;k<MAXN;++k)
        {
            for(int i=0;i<MAXN;++i)
            {
                for(int j=0;j<MAXN;++j)
                {
                    if(graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
        bool flag = false;
        int from, to;
        for(int i=0;i<MAXN;++i)
        {
            if(degree[i]&1)
            {
                if(flag)
                {
                    to = i;
                }
                else
                {
                    from = i;
                    flag = true;
                }
            }
        }
        if(flag)
        {
            sum += graph[from][to];
        }
        printf("%d\n",sum);
    }
    return 0;
}

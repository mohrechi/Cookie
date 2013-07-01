#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 35

int width, height;
char map[MAXN][MAXN];
char answer[MAXN][MAXN], answerNumber;
char tempPath[MAXN];

bool shadow(char x, char y, char alpha)
{
    return map[x][y] >= 'A' && map[x][y] <= 'Z' && map[x][y] != alpha;
}

bool movable(char alpha)
{
    char left, right, up, bottom;
    bool flag = false;
    left = up = MAXN;
    right = bottom = -1;
    for(char i=0;i<height;++i)
    {
        for(char j=0;j<width;++j)
        {
            if(alpha == map[i][j])
            {
                left = min(left, j);
                right = max(right, j);
                up = min(up, i);
                bottom = max(bottom, i);
                flag = true;
            }
        }
    }
    if(!flag)
    {
        return false;
    }
    for(char i=up;i<=bottom;++i)
    {
        if(shadow(i, left, alpha) || shadow(i, right, alpha))
        {
            return false;
        }
    }
    for(char j=left;j<=right;++j)
    {
        if(shadow(up, j, alpha) || shadow(bottom, j, alpha))
        {
            return false;
        }
    }
    return true;
}

void transfer(char origin, char target)
{
    for(char i=0;i<height;++i)
    {
        for(char j=0;j<width;++j)
        {
            if(map[i][j] == origin)
            {
                map[i][j] = target;
            }
        }
    }
}

void lower(char alpha)
{
    transfer(alpha, alpha - 'A' + 'a');
}

void upper(char alpha)
{
    transfer(alpha - 'A' + 'a', alpha);
}

bool end()
{
    for(char i=0;i<height;++i)
    {
        for(char j=0;j<width;++j)
        {
            if(shadow(i, j, ' '))
            {
                return false;
            }
        }
    }
    return true;
}

void search(char depth)
{
    if(end())
    {
        tempPath[depth] = 0;
        for(char i=0;i<depth;++i)
        {
            answer[answerNumber][i] = tempPath[depth-i-1];
        }
        answer[answerNumber++][depth] = 0;
        return;
    }
    for(char i='Z';i>='A';--i)
    {
        if(movable(i))
        {
            lower(i);
            tempPath[depth] = i;
            search(depth + 1);
            upper(i);
        }
    }
}

void sort()
{
    for(char i=0;i<answerNumber;++i)
    {
        for(char j=i+1;j<answerNumber;++j)
        {
            if(strcmp(answer[i], answer[j]) > 0)
            {
                strcpy(tempPath, answer[i]);
                strcpy(answer[i], answer[j]);
                strcpy(answer[j], tempPath);
            }
        }
    }
}

void output()
{
    sort();
    for(char i=0;i<answerNumber;++i)
    {
        printf("%s\n",answer[i]);
    }
}

int main(int argc, char *argv[])
{
    while(EOF!=scanf("%d%d",&height,&width))
    {
        for(char i=0;i<height;++i)
        {
            scanf("%s",map[i]);
        }
        answerNumber = 0;
        search(0);
        output();
    }
    return 0;
}

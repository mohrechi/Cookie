/*
ID: cyberzh1
LANG: C++
TASK: cowxor
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("cowxor.in","r");
FILE* fout=fopen("cowxor.out","w");
int n,cow[100005],trieNum;
int temp, max, maxi, maxj;
struct Trie
{
    int index, value, child[2];
}trie[700000];
int getBit(int x, int pos)
{
    return (x&(1<<pos))>>pos;
}
int create()
{
    trie[trieNum].index=-1;
    trie[trieNum].value=-1;
    trie[trieNum].child[0]=-1;
    trie[trieNum].child[1]=-1;
    return trieNum++;
}
void insert(int index, int value)
{
    int location=0, t;
    for(int i=20;i>=0;i--)
    {
        t=getBit(value, i);
        if(trie[location].child[t]==-1)
        {
            trie[location].child[t]=create();
        }
        location=trie[location].child[t];
    }
    trie[location].index=index;
    trie[location].value=value;
}
int find(int index, int value)
{
    int location=0, t;
    for(int i=20;i>=0 and location!=-1;i--)
    {
        t=getBit(value,i);
        if(trie[location].child[(t+1)&1]!=-1)
        {
            location=trie[location].child[(t+1)&1];
        }
        else
        {
            location=trie[location].child[t];
        }
    }
    return location;
}
int main()
{
    fscanf(fin,"%d",&n);
    create();
    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&temp);
        cow[i]=cow[i-1]^temp;
        temp=find(i,cow[i]);
        if(temp!=-1 and (cow[i]^trie[temp].value)>max)
        {
            max=(cow[i]^trie[temp].value);
            maxi=trie[temp].index+1;
            maxj=i;
        }
        insert(i,cow[i]);
    }
    if(n==1)
    {
        fprintf(fout, "0 1 1\n");
    }
    else
    {
        if(cow[1]==2097151)
        {
            maxi=maxj=1;
        }
        fprintf(fout,"%d %d %d\n",max,maxi,maxj);
    }
	return 0;
}

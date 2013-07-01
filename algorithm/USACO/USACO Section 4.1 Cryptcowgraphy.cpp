/*
ID: cyberzh1
LANG: C++
TASK: cryptcow
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* fin=fopen("cryptcow.in","r");
FILE* fout=fopen("cryptcow.out","w");
char target[100]="Begin the Escape execution at the Break of Dawn";
char origin[100];
char elf[1253][100][100];
int targetc[200],originc[200],keyPos[200][10];
long elfhash(char *key)
{
    long h=0;
    while(*key)
    {
        h=(h<<4)+*key++;
        long g=h&0Xf0000000L;
        if(g)
        {
            h^=g>>24;
        }
        h&=~g;
    }
    return h%1253;
}
bool judge(char text[],int len=48)
{
    for(int i=0;i<len;i++)
    {
        if(text[i]!=target[i])
        {
            return false;
        }
    }
    return true;
}
bool judgem(char text[],int a, int b)
{
    char temp[100];
    int j=0;
    for(int i=a+1;i<b;i++)
    {
        temp[j++]=text[i];
    }
    temp[j]=0;
    return not strstr(target,temp)==0;
}
void deal(char text[], char from[], int a, int b, int c)
{
    int len=strlen(from),i=0,j=0;
    for(;i<a;i++)
    {
        text[j++]=from[i];
    }
    for(i=b+1;i<c;i++)
    {
        text[j++]=from[i];
    }
    for(i=a+1;i<b;i++)
    {
        text[j++]=from[i];
    }
    for(i=c+1;i<len;i++)
    {
        text[j++]=from[i];
    }
    text[j]=0;
}
bool midCheck(char text[])
{
    int i,j,k,len=strlen(text);
    i=-1;
    for(int i=0;i<len;i++)
    {
        if(text[i]=='C')
        {
            break;
        }
    }
    k=i+1,j=1;
    for(i++;i<len;i++)
    {
        if(text[i]=='C' or text[i]=='O' or text[i]=='W')
        {
            j=1,k=i+1;
        }
        else if(text[i]!=target[keyPos[text[k]][j]+i-k])
        {
            j++,i=k-1;
            if(j>keyPos[text[k]][0])
            {
                return 0;
            }
        }
    }
    return 1;
}
void DFS(char change[], int cows)
{
    int len=strlen(change),last;
    char temp[100];
    int l=46;
    for(int i=len-1;i>=0;i--)
    {
        if(change[i]!='W')
        {
            if(change[i]!=target[l--])
            {
                return;
            }
        }
        else
        {
            break;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(change[i]!='C')
        {
            if(change[i]!=target[i])
            {
                return;
            }
        }
        else
        {
            break;
        }
    }
    if(not midCheck(change))
    {
        return;
    }
    int f=elfhash(change),g=0;
    while(elf[f][g][0]!=0)
    {
        if(not strcmp(elf[f][g],change))
        {
            break;
        }
        g++;
    }
    if(elf[f][g][0]==0)
    {
        strcpy(elf[f][g],change);
    }
    else
    {
        return;
    }
    for(int i=0;i<len;i++)
    {
        if(change[i]=='O')
        {
            for(int j=i-1;j>=0;j--)
            {
                if(change[j]=='C')
                {
                    for(int k=len-1;k>i;k--)
                    {
                        if(change[k]=='W')
                        {
                            deal(temp,change,j,i,k);
                            if(judge(temp))
                            {
                                fprintf(fout,"1 %d\n",cows);
                                exit(0);
                            }
                            DFS(temp,cows+1);
                        }
                    }
                }
            }
        }
    }
}
void initPos()
{
    int len=strlen(target);
    for(int i=0;i<len;i++)
    {
        keyPos[target[i]][0]++;
        keyPos[target[i]][keyPos[target[i]][0]]=i;
    }
}
int main()
{
    fgets(origin,sizeof(origin)-1,fin);
    int len=strlen(origin);
    while(origin[len-1]=='\n')
    {
        origin[--len]=0;
    }
    if(not strcmp(origin,target))
    {
        fprintf(fout,"1 0\n");
        return 0;
    }
    if((len-47)%3)
    {
        fprintf(fout,"0 0\n");
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        if(origin[i]!='C' and origin[i]!='O' and origin[i]!='W')
        {
            originc[origin[i]]++;
        }
    }
    for(int i=0;i<48;i++)
    {
        targetc[target[i]]++;
    }
    for(int i=1;i<200;i++)
    {
        if(originc[i]!=targetc[i])
        {
            fprintf(fout,"0 0\n");
            return 0;
        }
    }
    initPos();
    DFS(origin,1);
    fprintf(fout,"0 0\n");
    return 0;
}

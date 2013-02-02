/*
ID: cyberzh1
LANG: C++
TASK: heritage
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* fin=fopen("heritage.in","r");
FILE* fout=fopen("heritage.out","w");
void build(int len, char l[], char m[], char r[])
{
    if(len<=0) return;
    int p=strchr(m,l[0])-m;
    build(p,l+1,m,r);
    build(len-p-1,l+p+1,m+p+1,r+p);
    r[len-1]=l[0];
}
int main()
{
    char m[1000],l[1000],r[1000];
    fscanf(fin,"%s%s",m,l);
    int len=strlen(l);
    build(len,l,m,r);
    r[len]=0;
    fprintf(fout,"%s\n",r);
	return 0;
}

/*
ID: cyberzh1
LANG: C++
TASK: namenum
*/
#include<stdio.h>
#include<string.h>

char getNum(char ch)
{
    switch (ch)
    {
        case 'A': case 'B': case 'C': return '2';
        case 'D': case 'E': case 'F': return '3';
        case 'G': case 'H': case 'I': return '4';
        case 'J': case 'K': case 'L': return '5';
        case 'M': case 'N': case 'O': return '6';
        case 'P': case 'R': case 'S': return '7';
        case 'T': case 'U': case 'V': return '8';
        case 'W': case 'X': case 'Y': return '9';
    }
    return '0';
}

int main()
{
    FILE* fin=fopen("namenum.in","r");
    FILE* fout=fopen("namenum.out","w");
    char num[20];
    fscanf(fin,"%s",num);
    FILE* dict=fopen("dict.txt","r");
    char s[20];
    bool flag=true;
    while(fscanf(dict,"%s",s)!=EOF)
    {
        int len=strlen(s);
        char temp[20];
        strcpy(temp,s);
        for(int i=0;i<len;i++)
        {
            s[i]=getNum(s[i]);
        }
        if(not strcmp(num,s))
        {
            fprintf(fout,"%s\n",temp);
            flag=false;
        }
    }
    if(flag)
    {
        fprintf(fout,"NONE\n");
    }
    return 0;
}

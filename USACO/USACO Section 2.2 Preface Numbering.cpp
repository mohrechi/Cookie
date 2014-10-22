/*
ID: cyberzh1
LANG: C++
TASK: preface
*/
#include<stdio.h>
#include<string.h>
FILE* fin=fopen("preface.in","r");
FILE* fout=fopen("preface.out","w");
char romal[]={'I','V','X','L','C','D','M'};
char num[][5]={"-","I","II","III","IV","V","VI","VII","VIII","IX",
                "-","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
                "-","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
                "-","M","MM","MMM"};
int ans[7]={0};
void changeRomal(int number)
{
    int index=0;
    while(number>0)
    {
        int temp=index*10+number%10;
        int len=strlen(num[temp]);
        for(int i=0;i<len;i++)
        {
            switch (num[temp][i])
            {
                case 'I': ans[0]++; break;
                case 'V': ans[1]++; break;
                case 'X': ans[2]++; break;
                case 'L': ans[3]++; break;
                case 'C': ans[4]++; break;
                case 'D': ans[5]++; break;
                case 'M': ans[6]++; break;
            }
        }
        number/=10;
        index++;
    }
}
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++)
    {
        changeRomal(i);
    }
    for(int i=0;i<7;i++)
    {
        if(ans[i])
        {
            fprintf(fout,"%c %d\n",romal[i],ans[i]);
        }
    }
    return 0;
}

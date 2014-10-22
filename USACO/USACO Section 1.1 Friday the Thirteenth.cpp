/*
ID: cyberzh1
LANG: C++
TASK: friday
*/

#include<stdio.h>

bool run(int year)
{
    return year%400==0 or (year%4==0 and year%100!=0);
}

int getDay(int month, int year)
{
    if(month==1 or month==3 or month==5 or month==7 or month==8 or month==10 or month==12) return 31;
    if(month==4 or month==6 or month==9 or month==11) return 30;
    if(run(year))return 29;
    return 28;
}

int main()
{
    FILE *fin=fopen("friday.in","r");
    FILE *fout=fopen("friday.out","w");
    int n,ans[7],day,firstDay=2;
    fscanf(fin,"%d",&n);
    for(int i=0;i<7;i++)
    {
        ans[i]=0;
    }
    day=0;
    for(int i=1900;i<1900+n;i++)
    {
        for(int j=1;j<=12;j++)
        {
            ans[(firstDay+5)%7]++;
            firstDay=(firstDay+getDay(j,i))%7;
        }
    }
    fprintf(fout,"%d",ans[0]);
    for(int i=1;i<7;i++)
    {
        fprintf(fout," %d",ans[i]);
    }
    fprintf(fout,"\n");
    return 0;
}

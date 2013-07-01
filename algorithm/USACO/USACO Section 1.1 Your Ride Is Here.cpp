/*
ID: cyberzh1
LANG: C++
TASK: ride
*/

#include <stdio.h>
#include <string.h>
int main ()
{
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char s1[100],s2[100];
    fscanf (fin, "%s%s",s1,s2);
    int l1, l2, m1=1, m2=1;
    l1=strlen(s1);
    l2=strlen(s2);
    for(int i=0;i<l1;i++)
    {
        m1*=s1[i]-64;
        m1%=47;
    }
    for(int i=0;i<l2;i++)
    {
        m2*=s2[i]-64;
        m2%=47;
    }
    if(m1 == m2) fprintf (fout, "GO\n");
    else fprintf (fout, "STAY\n");
    return 0;
}

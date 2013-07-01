/*
ID: cyberzh1
LANG: C++
TASK: gift1
*/

#include <stdio.h>
#include <string.h>
int main ()
{
    FILE *fin  = fopen ("gift1.in", "r");
    FILE *fout = fopen ("gift1.out", "w");
    int n,initial[20],final[20];
    char name[20][20];
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%s",name[i]);
        final[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%s",name[19]);
        for(int j=0;j<n;j++)
        {
            if(not strcmp(name[19],name[j]))
            {
                int t,r;
                fscanf(fin,"%d%d",&initial[j],&t);
                if(t==0)
                {
                    final[j]+=initial[j];
                    break;
                }
                r=initial[j]/t;
                final[j]+=initial[j]-t*r;
                for(int k=0;k<t;k++)
                {
                    fscanf(fin,"%s",name[19]);
                    for(int l=0;l<n;l++)
                    {
                        if(not strcmp(name[19],name[l]))
                        {
                            final[l]+=r;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fout,"%s %d\n",name[i],final[i]-initial[i]);
    }
    return 0;
}

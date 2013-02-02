/*
ID: cyberzh1
LANG: C++
TASK: transform
*/
#include<stdio.h>

int n,a[15][15],b[15][15],temp[15][15];

bool compare()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool rotate()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[j][n-i-1]=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=temp[i][j];
        }
    }
    return compare();
}

bool reflect()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][n-j-1]=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=temp[i][j];
        }
    }
    return compare();
}

int main()
{
    FILE *fin=fopen("transform.in","r");
    FILE *fout=fopen("transform.out","w");
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;)
        {
            char ch;
            fscanf(fin,"%c",&ch);
            if(ch=='@')
            {
                a[i][j++]=1;
            }
            if(ch=='-')
            {
                a[i][j++]=0;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;)
        {
            char ch;
            fscanf(fin,"%c",&ch);
            if(ch=='@')
            {
                b[i][j++]=1;
            }
            if(ch=='-')
            {
                b[i][j++]=0;
            }
        }
    }
    if(rotate())
    {
        fprintf(fout,"1\n");
    }
    else
    {
        if(rotate())
        {
            fprintf(fout,"2\n");
        }
        else
        {
            if(rotate())
            {
                fprintf(fout,"3\n");
            }
            else
            {
                rotate();
                if(reflect())
                {
                    fprintf(fout,"4\n");
                }
                else
                {
                    if(rotate() or rotate() or rotate())
                    {
                        fprintf(fout,"5\n");
                    }
                    else
                    {
                        rotate();
                        if(reflect())
                        {
                            fprintf(fout,"6\n");
                        }
                        else
                        {
                            fprintf(fout,"7\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}

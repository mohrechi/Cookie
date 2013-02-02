/*
ID: cyberzh1
LANG: C++
TASK: checker
*/
#include<stdio.h>

int n,num,ans[20],pr;
bool row[20],diag1[40],diag2[40];
FILE *fin,*fout;

void dfs(int layer,int max)
{
    for(int i=1;i<=max;i++)
    {
        if(not row[i] and not diag1[i+layer] and not diag2[i-layer+n])
        {
            ans[layer]=i;
            if(layer==n)
            {
                num++;
                if(++pr<=3)
                {
                    fprintf(fout,"%d",ans[1]);
                    for(int j=2;j<=n;j++)
                    {
                        fprintf(fout," %d",ans[j]);
                    }
                    fprintf(fout,"\n");
                }
                if(n>6 and ans[1]<=n/2)
                {
                    num++;
                }
            }
            else
            {
                row[i]=true;
                diag1[i+layer]=true;
                diag2[i-layer+n]=true;
                dfs(layer+1,n);
                row[i]=false;
                diag1[i+layer]=false;
                diag2[i-layer+n]=false;
            }
        }
    }
}

int main()
{
    fin=fopen("checker.in","r");
    fout=fopen("checker.out","w");
    fscanf(fin,"%d",&n);
    num=0,pr=0;
    dfs(1,n>6?(n+1)/2:n);
    fprintf(fout,"%d\n",num);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int n,k,score[1005],temp,hu;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            score[i]=0;
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&temp);
                score[i]+=temp;
            }
        }
        hu=score[1];
        qsort(score+1,n,sizeof(int),cmp);
        int i=1;
        for(;i<=n;i++)
        {
            if(score[i]<hu)
            {
                break;
            }
        }
        printf("%d\n",i-1);
    }
    return 0;
}

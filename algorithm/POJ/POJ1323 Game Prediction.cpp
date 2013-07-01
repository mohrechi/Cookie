#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,m,num[1005],caseNum=0;
    while(scanf("%d%d",&n,&m),n||m)
    {
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&num[i]);
        }
        int n1=0,n2=0;
        qsort(num+1,m,sizeof(int),cmp);
        for(int i=n*m;i>=1,m>0;--i)
        {
            if(num[m]!=i) n1++;
            else
            {
                if(n1) n1--;
                else ans++;
                m--;
            }
        }
        printf("Case %d: %d\n",++caseNum,ans);
    }
	return 0;
}

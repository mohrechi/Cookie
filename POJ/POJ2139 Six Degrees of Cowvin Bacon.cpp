#include <cstdio>
static const int MAXN = 305;
int path[MAXN][MAXN];
int sameMovie[MAXN];

int main(int argc, char *argv[])
{
    int cowNumber, movieNumber, friendsNumber;
    scanf("%d%d",&cowNumber,&movieNumber);
    for(int i=1;i<=cowNumber;++i)
    {
        for(int j=1;j<=cowNumber;++j)
        {
            path[i][j] = 1000000000;
        }
        path[i][i] = 0;
    }
    for(int k=0;k<movieNumber;++k)
    {
        scanf("%d",&friendsNumber);
        for(int i=0;i<friendsNumber;++i)
        {
            scanf("%d",&sameMovie[i]);
        }
        for(int i=0;i<friendsNumber;++i)
        {
            for(int j=i+1;j<friendsNumber;++j)
            {
                path[sameMovie[i]][sameMovie[j]] = path[sameMovie[j]][sameMovie[i]] = 100;
            }
        }
    }
    for(int k=1;k<=cowNumber;++k)
    {
        for(int i=1;i<=cowNumber;++i)
        {
            for(int j=1;j<=cowNumber;++j)
            {
                if(path[i][k] + path[k][j] < path[i][j])
                {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    int total, min = 0x7FFFFFFF;
    for(int i=1;i<=cowNumber;++i)
    {
        total = 0;
        for(int j=1;j<=cowNumber;++j)
        {
            total += path[i][j];
        }
        total /= (cowNumber - 1);
        if(total < min)
        {
            min = total;
        }
    }
    printf("%d\n",min);
    return 0;
}

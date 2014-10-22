#include<stdio.h>

const int MAXN = 10005;
int clusterNumber;
int cluster[MAXN];
int clusterPointer[MAXN];
int totalFileCluster;
int firstCluster;
bool firstFlag;

void input()
{
    int fileNumber,fileClusterNumber,currentCluster;
    scanf("%d%d",&clusterNumber,&fileNumber);
    while(fileNumber--)
    {
        scanf("%d",&fileClusterNumber);
        while(fileClusterNumber--)
        {
            scanf("%d",&currentCluster);
            cluster[currentCluster] = ++totalFileCluster;
            clusterPointer[totalFileCluster] = currentCluster;
        }
    }
}

bool prevJudge()
{
    for(int i=1;i<=totalFileCluster;++i)
    {
        if(cluster[i] != i)
        {
            return false;
        }
    }
    return true;
}

void move(int clusterIndex)
{
    if(cluster[clusterIndex] == clusterIndex)
    {
        return;
    }
    if(cluster[clusterIndex] == 0)
    {
        cluster[clusterIndex] = clusterIndex;
        cluster[clusterPointer[clusterIndex]] = 0;
        printf("%d %d\n",clusterPointer[clusterIndex], clusterIndex);
    }
    else
    {
        if(clusterIndex == firstCluster)
        {
            if(firstFlag)
            {
                firstFlag = false;
                move(cluster[clusterIndex]);
            }
            else
            {
                for(int i=clusterNumber;i>=1;--i)
                {
                    if(cluster[i] == 0)
                    {
                        cluster[i] = clusterIndex;
                        cluster[clusterPointer[clusterIndex]] = 0;
                        printf("%d %d\n",clusterPointer[clusterIndex],i);
                        clusterPointer[clusterIndex] = i;
                        return;
                    }
                }
            }
        }
        else
        {
            move(cluster[clusterIndex]);
        }
        cluster[clusterIndex] = clusterIndex;
        cluster[clusterPointer[clusterIndex]] = 0;
        printf("%d %d\n",clusterPointer[clusterIndex], clusterIndex);
    }
}

int main(int argc, char *argv[])
{
    input();
    if(prevJudge())
    {
        printf("No optimization needed\n");
    }
    else
    {
        for(int i=1;i<=totalFileCluster;++i)
        {
            firstCluster = i;
            firstFlag = true;
            move(i);
            move(i);
        }
    }
    return 0;
}

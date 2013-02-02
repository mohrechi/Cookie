#include<stdio.h>

struct Cube
{
    int identifier;
    int neighbor[4][2];
    bool used;
    int color;
    int pos[4];
    void input()
    {
        scanf("%d",&identifier);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<2;j++)
            {
                scanf("%d",&neighbor[i][j]);
            }
            pos[i]=0;
        }
        used=false;
        color=identifier;
    }
}cubes[200];

int cubeNum;

int find(int identifier)
{
    for(int i=0;i<cubeNum;i++)
    {
        if(cubes[i].identifier==identifier)
        {
            if(cubes[i].color==identifier)
            {
                return identifier;
            }
            return cubes[i].color=find(cubes[i].color);
        }
    }
    return -1;
}

void combine(int x, int y)
{
    x=find(x), y=find(y);
    for(int i=0;i<cubeNum;i++)
    {
        if(cubes[i].identifier==x)
        {
            cubes[i].color=y;
        }
    }
}

bool symmetricCheck()
{
    for(int i=0;i<cubeNum;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int d=0;d<2;d++)
            {
                if(cubes[i].neighbor[j][d])
                {
                    for(int k=0;k<cubeNum;k++)
                    {
                        if(cubes[k].identifier==cubes[i].neighbor[j][d])
                        {
                            if(cubes[k].neighbor[j][d^1]!=cubes[i].identifier)
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool solidCheck()
{
    for(int i=0;i<cubeNum;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int d=0;d<2;d++)
            {
                if(cubes[i].neighbor[j][d])
                {
                    combine(cubes[i].identifier, cubes[i].neighbor[j][d]);
                }
            }
        }
    }
    for(int i=1;i<cubeNum;i++)
    {
        if(find(cubes[i].identifier)!=find(cubes[0].identifier))
        {
            return false;
        }
    }
    return true;
}

void givePos(int identifier, int dimention, bool left, int pos[4])
{
    for(int i=0;i<cubeNum;i++)
    {
        if(cubes[i].identifier==identifier)
        {
            if(!cubes[i].used)
            {
                for(int j=0;j<4;j++)
                {
                    cubes[i].pos[j]=pos[j];
                }
                if(left) --cubes[i].pos[dimention];
                else ++cubes[i].pos[dimention];
                cubes[i].used=true;
                for(int j=0;j<4;j++)
                {
                    for(int k=0;k<2;k++)
                    {
                        if(cubes[i].neighbor[j][k])
                        {
                            givePos(cubes[i].neighbor[j][k],j,k,cubes[i].pos);
                        }
                    }
                }
            }
            return;
        }
    }
}

int getArea()
{
    int max[4],min[4];
    for(int i=0;i<4;i++)
    {
        max[i]=-200;
        min[i]=200;
    }
    for(int i=0;i<cubeNum;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(cubes[i].pos[j]>max[j]) max[j]=cubes[i].pos[j];
            if(cubes[i].pos[j]<min[j]) min[j]=cubes[i].pos[j];
        }
    }
    int ans=1;
    for(int i=0;i<4;i++)
    {
        ans*=max[i]-min[i]+1;
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&cubeNum);
        for(int i=0;i<cubeNum;i++)
        {
            cubes[i].input();
        }
        if(!symmetricCheck())
        {
            printf("Inconsistent\n");
            continue;
        }
        if(!solidCheck())
        {
            printf("Inconsistent\n");
            continue;
        }
        cubes[0].used=true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(cubes[0].neighbor[i][j])
                {
                    givePos(cubes[0].neighbor[i][j],i,j,cubes[0].pos);
                }
            }
        }
        printf("%d\n",getArea());
    }
    return 0;
}

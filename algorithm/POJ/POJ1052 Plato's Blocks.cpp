#include <stdio.h>
#include <memory.h>
//#define DEBUG
#define MAXN 25

int length, dataNumber;
bool cube[MAXN][MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN];
char panel[8][3][MAXN][MAXN];
int directionX[] = {1,0,0,-1,0,0};
int directionY[] = {0,1,0,0,-1,0};
int directionZ[] = {0,0,1,0,0,-1};

bool input()
{
    scanf("%d",&length);
    for(int k=0;k<3;++k)
    {
        for(int i=1;i<=length;++i)
        {
            scanf("%s",panel[0][k][i]+1);
        }
    }
    return length != 0;
}

void search(int x, int y, int z)
{
    if(!visited[x][y][z])
    {
        visited[x][y][z] = true;
        if(x >= 1 && x <= length)
        {
            if(y >= 1 && y <= length)
            {
                if(z >= 1 && z <= length)
                {
                    if(cube[x][y][z])
                    {
                        for(int i=0;i<6;++i)
                        {
                            search(x + directionX[i], y + directionY[i], z + directionZ[i]);
                        }
                    }
                }
            }
        }
    }
}

void makeCube(int p1, int p2, int p3)
{
    memset(cube, true, sizeof(cube));
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p1][0][i][j] == '-')
            {
                for(int k=1;k<=length;++k)
                {
                    cube[i][j][k] = false;
                }
            }
        }
    }
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p2][1][i][j] == '-')
            {
                for(int k=1;k<=length;++k)
                {
                    cube[k][i][j] = false;
                }
            }
        }
    }
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p3][2][i][j] == '-')
            {
                for(int k=1;k<=length;++k)
                {
                    cube[i][k][j] = false;
                }
            }
        }
    }
}

bool checkMatchOrigin(int p1, int p2, int p3)
{
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p1][0][i][j] == 'X')
            {
                bool flag = false;
                for(int k=1;k<=length;++k)
                {
                    if(cube[i][j][k])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    return false;
                }
            }
        }
    }
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p2][1][i][j] == 'X')
            {
                bool flag = false;
                for(int k=1;k<=length;++k)
                {
                    if(cube[k][i][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    return false;
                }
            }
        }
    }
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            if(panel[p3][2][i][j] == 'X')
            {
                bool flag = false;
                for(int k=1;k<=length;++k)
                {
                    if(cube[i][k][j])
                    {
                        flag = true;
                        break;
                    }
                }
                if(!flag)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool checkTogether()
{
    memset(visited, false, sizeof(visited));
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            for(int k=1;k<=length;++k)
            {
                if(cube[i][j][k])
                {
                    search(i,j,k);
                    for(int x=1;x<=length;++x)
                    {
                        for(int y=1;y<=length;++y)
                        {
                            for(int z=1;z<=length;++z)
                            {
                                if(cube[x][y][z] && !visited[x][y][z])
                                {
                                    return false;
                                }
                            }
                        }
                    }
                    return true;
                }
            }
        }
    }
    return true;
}

void rotatePanel(char tempArray[MAXN][MAXN], char array[MAXN][MAXN])
{
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            tempArray[j][length - i + 1] = array[i][j];
        }
    }
}

void mirrorPanel(char tempArray[MAXN][MAXN], char array[MAXN][MAXN])
{
    for(int i=1;i<=length;++i)
    {
        for(int j=1;j<=length;++j)
        {
            tempArray[length - i + 1][j] = array[i][j];
        }
    }
}

void makePanel()
{
    for(int i=1;i<=3;++i)
    {
        for(int j=0;j<3;++j)
        {
            rotatePanel(panel[i][j], panel[i-1][j]);
        }
    }
    for(int i=4;i<=7;++i)
    {
        for(int j=0;j<3;++j)
        {
            mirrorPanel(panel[i][j], panel[i-4][j]);
        }
    }
}

bool checkPossibility()
{
    makePanel();
    #ifdef DEBUG
        freopen("out.txt","w",stdout);
        printf("Shadow: \n");
        for(int i=0;i<8;++i)
        {
            for(int l=0;l<3;++l)
            {
                for(int j=1;j<=length;++j)
                {
                    for(int k=1;k<=length;++k)
                    {
                        printf("%c",panel[i][l][j][k]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
    #endif
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            for(int k=0;k<8;++k)
            {
                makeCube(i,j,k);
                #ifdef DEBUG
                    printf("Cube: \n");
                    for(int x=length;x>=1;--x)
                    {
                        for(int z=length;z>=1;--z)
                        {
                            for(int y=1;y<=length;++y)
                            {
                                printf("%d ",cube[x][y][z]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                    printf("\n");
                #endif
                if(checkMatchOrigin(i,j,k) && checkTogether())
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    //freopen("in.txt","r",stdin);
    while(input())
    {
        printf("Data set %d: ",++dataNumber);
        if(checkPossibility())
        {
            printf("Valid set of patterns\n");
        }
        else
        {
            printf("Impossible combination\n");
        }
    }
    return 0;
}

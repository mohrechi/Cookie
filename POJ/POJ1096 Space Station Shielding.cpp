#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

int n,m,k,l,t,c,x,y,z;
bool cube[65][65][65];
bool out[65][65][65];
int stepX[6] = {-1,0,0,1,0,0};
int stepY[6] = {0,-1,0,0,1,0};
int stepZ[6] = {0,0,-1,0,0,1};

void setOut(int x, int y, int z)
{
    if(x >= 0)
    {
        if(y >= 0)
        {
            if(z >= 0)
            {
                if(x <= n+1)
                {
                    if(y <= m+1)
                    {
                        if(z <= k+1)
                        {
                            if(!out[x][y][z])
                            {
                                if(!cube[x][y][z])
                                {
                                    out[x][y][z] = true;
                                    for(int i=0;i<6;i++)
                                    {
                                        setOut(x+stepX[i], y+stepY[i], z+stepZ[i]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    while(scanf("%d%d%d%d",&n,&m,&k,&l),n||m||k||l)
    {
        memset(cube, false, sizeof(cube));
        memset(out, false, sizeof(out));
        c = 0;
        for(int i=0;i<l;i++)
        {
            scanf("%d",&t);
            x = t % n + 1;
            y = (t % (m * n)) / n + 1;
            z = t / (m * n) + 1;
            cube[x][y][z] = true;
        }
        setOut(0,0,0);
        for(x=1;x<=n;x++)
        {
            for(y=1;y<=m;y++)
            {
                for(z=1;z<=k;z++)
                {
                    for(l=0;l<6;l++)
                    {
                        if(cube[x][y][z])
                        {
                            if(out[x+stepX[l]][y+stepY[l]][z+stepZ[l]])
                            {
                                ++ c;
                            }
                        }
                    }
                }
            }
        }
        printf("The number of faces needing shielding is %d.\n", c);
    }
    return 0;
}

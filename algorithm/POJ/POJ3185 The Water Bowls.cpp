#include <cstdio>

int min(const int x, const int y)
{
    return x<y?x:y;
}

int main(int argc, char *argv[])
{
    int bowl[22], way[2][22];
    int res[2] = {0, 1};
    for(int i=1;i<=20;++i)
    {
        scanf("%d",&bowl[i]);
        way[0][i] = way[1][i] = 0;
    }
    way[0][0] = way[1][0] = way[0][21] = way[1][21] = 0;
    way[1][1] = 1;
    for(int i=1;i<20;++i)
    {
        for(int j=0;j<2;++j)
        {
            if((way[j][i-1] + way[j][i] + bowl[i])&1)
            {
                ++res[j];
                way[j][i+1] = 1;
            }
        }
    }
    printf("%d\n",min(res[0], res[1]));
    return 0;
}

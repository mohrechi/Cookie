#include <stdio.h>
#include <memory.h>

const int MAXN = 2005;

int polynomials[4][MAXN];
int polynomialsTop[4];

void input()
{
    memset(polynomials, 0, sizeof(polynomials));
    for(int i=0;i<3;++i)
    {
        scanf("%d",&polynomialsTop[i]);
        for(int j=polynomialsTop[i]-1;j>=0;--j)
        {
            scanf("%d",&polynomials[i][j]);
        }
    }
}

void multiplication()
{
    for(int i=0;i<polynomialsTop[0];++i)
    {
        for(int j=0;j<polynomialsTop[1];++j)
        {
            polynomials[3][i+j] ^= polynomials[0][i] * polynomials[1][j];
        }
    }
    polynomialsTop[3] = polynomialsTop[1] + polynomialsTop[2];
    while(polynomialsTop[3] > 0 && polynomials[3][polynomialsTop[3]-1] == 0)
    {
        --polynomialsTop[3];
    }
}

void modulo()
{
    while(polynomialsTop[3] >= polynomialsTop[2])
    {
        int dist = polynomialsTop[3] - polynomialsTop[2];
        for(int i=polynomialsTop[2]-1;i>=0;--i)
        {
            polynomials[3][i+dist] ^= polynomials[2][i];
        }
        while(polynomialsTop[3] > 0 && polynomials[3][polynomialsTop[3]-1] == 0)
        {
            --polynomialsTop[3];
        }
    }
}

void output()
{
    printf("%d",polynomialsTop[3]);
    for(int i=polynomialsTop[3]-1;i>=0;--i)
    {
        printf(" %d",polynomials[3][i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        input();
        multiplication();
        modulo();
        output();
    }
}

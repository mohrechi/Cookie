#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int key[4][4] =
{
    {2, 3, 1, 1},
    {1, 2, 3, 1},
    {1, 1, 2, 3},
    {3, 1, 1, 2}
};

int m[4][4];

int transDecFromHex(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    return ch - 'A' + 10;
}

char transHexFromDec(int x)
{
    if(x >= 0 && x <= 9)
    {
        return x + '0';
    }
    return x - 10 + 'A';
}

int getDecFromHex()
{
    char s[10];
    scanf("%s", s);
    return (transDecFromHex(s[0]) << 4) + transDecFromHex(s[1]);
}

void printDecToHex(int x)
{
    printf("%c", transHexFromDec(x>>4));
    printf("%c", transHexFromDec(x & 0x0f));
}

int shift(int x)
{
    x <<= 1;
    if(x > 0xff)
    {
        x ^= 0x1b;
    }
    x &= 0xff;
    return x;
}

int solve(int temp[4], int stand[4])
{
    for(int i=0;i<4;++i)
    {
        if(stand[i] == 2)
        {
            temp[i] = shift(temp[i]);
        }
        else if(stand[i] == 3)
        {
            temp[i] ^= shift(temp[i]);
        }
    }
    int ans = 0;
    for(int i=0;i<4;++i)
    {
        ans ^= temp[i];
    }
    return ans;
}

void solve(int temp[4])
{
    int stand[4];
    int out[4];
    int copy[4];
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            copy[j] = temp[j];
            stand[j] = key[i][j];
        }
        out[i] = solve(copy, stand);
    }
    for(int i=0;i<4;++i)
    {
        temp[i] = out[i];
    }
}

void solve()
{
    int temp[4];
    for(int i=0;i<4;++i)
    {
        for(int j=0;j<4;++j)
        {
            temp[j] = m[j][i];
        }
        solve(temp);
        for(int j=0;j<4;++j)
        {
            m[j][i] = temp[j];
        }
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=0;cas<caseNumber;++cas)
    {
        if(cas)
        {
            printf("\n");
        }
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                m[i][j] = getDecFromHex();
            }
        }
        solve();
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<4;++j)
            {
                if(j)
                {
                    printf(" ");
                }
                printDecToHex(m[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

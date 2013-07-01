#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

__int64 v;
__int64 mat[4][3][3];
__int64 vec[2][3];

inline void matMul(__int64 a[3][3], __int64 b[3][3])
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            mat[2][i][j] = 0;
            for(int k=0;k<3;++k)
            {
                mat[2][i][j] += (a[i][k] * b[k][j]) % MOD;
                mat[2][i][j] %= MOD;
            }
        }
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            a[i][j] = mat[2][i][j];
        }
    }
}

inline void matMul()
{
    matMul(mat[0], mat[1]);
}

inline void matMul(__int64 a[3], __int64 b[3][3])
{
    for(int i=0;i<3;++i)
    {
        vec[1][i] = 0;
        for(int j=0;j<3;++j)
        {
            vec[1][i] += (a[j] * b[j][i]) % MOD;
            vec[1][i] % MOD;
        }
    }
    for(int i=0;i<3;++i)
    {
        a[i] = vec[1][i];
    }
}

inline __int64 getNum(const char *s)
{
    __int64 res = 0;
    for(int i=0;s[i];++i)
    {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

inline void clrMat()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            mat[1][i][j] = 0;
        }
    }
    mat[1][2][2] = 1;
}

inline void set11()
{
    mat[1][0][0] = 1;
    mat[1][1][1] = 1;
}

inline void set12()
{
    mat[1][1][0] = 1;
    mat[1][1][1] = 1;
}

inline void set21()
{
    mat[1][0][0] = 1;
    mat[1][0][1] = 1;
}

inline void set22()
{
    mat[1][0][0] = 1;
    mat[1][1][1] = 1;
}

inline void set1n(__int64 n)
{
    mat[1][2][0] = n;
    mat[1][1][1] = 1;
}

inline void set2n(__int64 n)
{
    mat[1][0][0] = 1;
    mat[1][2][1] = n;
}

inline void add11()
{
    mat[1][0][0] = 2;
    mat[1][1][1] = 1;
}

inline void add12()
{
    mat[1][0][0] = 1;
    mat[1][1][0] = 1;
    mat[1][1][1] = 1;
}

inline void add21()
{
    mat[1][0][0] = 1;
    mat[1][0][1] = 1;
    mat[1][1][1] = 1;
}

inline void add22()
{
    mat[1][0][0] = 1;
    mat[1][1][1] = 2;
}

inline void add1n(__int64 n)
{
    mat[1][0][0] = 1;
    mat[1][1][1] = 1;
    mat[1][2][0] = n;
}

inline void add2n(__int64 n)
{
    mat[1][0][0] = 1;
    mat[1][1][1] = 1;
    mat[1][2][1] = n;
}

inline void mul1n(__int64 n)
{
    mat[1][0][0] = n;
    mat[1][1][1] = 1;
}

inline void mul2n(__int64 n)
{
    mat[1][0][0] = 1;
    mat[1][1][1] = n;
}

void getMat()
{
    for(int i=0;i<3;++i)
    {
        mat[0][i][i] = 1;
        for(int j=i+1;j<3;++j)
        {
            mat[0][i][j] = mat[0][j][i] = 0;
        }
    }
    char s[100];
    scanf("%I64d\n", &v);
    while(scanf("%s", s))
    {
        clrMat();
        switch(*s)
        {
            case 'S':
                scanf("%s", s);
                if(s[1] == '1')
                {
                    scanf("%s", s);
                    if(s[0] == 'C')
                    {
                        if(s[1] == '1')
                        {
                            set11();
                        }
                        else
                        {
                            set12();
                        }
                    }
                    else
                    {
                        set1n(getNum(s));
                    }
                }
                else
                {
                    scanf("%s", s);
                    if(s[0] == 'C')
                    {
                        if(s[1] == '1')
                        {
                            set21();
                        }
                        else
                        {
                            set22();
                        }
                    }
                    else
                    {
                        set2n(getNum(s));
                    }
                }
                break;
            case 'A':
                scanf("%s", s);
                if(s[1] == '1')
                {
                    scanf("%s", s);
                    if(s[0] == 'C')
                    {
                        if(s[1] == '1')
                        {
                            add11();
                        }
                        else
                        {
                            add12();
                        }
                    }
                    else
                    {
                        add1n(getNum(s));
                    }
                }
                else
                {
                    scanf("%s", s);
                    if(s[0] == 'C')
                    {
                        if(s[1] == '1')
                        {
                            add21();
                        }
                        else
                        {
                            add22();
                        }
                    }
                    else
                    {
                        add2n(getNum(s));
                    }
                }
                break;
            case 'M':
                scanf("%s", s);
                if(s[1] == '1')
                {
                    scanf("%s", s);
                    mul1n(getNum(s));
                }
                else
                {
                    scanf("%s", s);
                    mul2n(getNum(s));
                }
                break;
            case 'E':
                return;
        }
        matMul();

        for(int i=0;i<3;++i)
        {
            for(int j=0;j<3;++j)
            {
                //printf("%I64d ", mat[0][i][j]);
            }
            //printf("\n");
        }
    }
}

void getResult(char *s)
{
    int len;
    for(len=0;s[len];++len)
    {
        s[len] -= '0';
    }
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            mat[1][i][j] = mat[0][i][j];
            mat[3][i][j] = 0;
        }
        mat[3][i][i] = 1;
    }
    bool flag = true;
    while(flag)
    {
        flag = false;
        int mod = 0;
        for(int i=0;i<len;++i)
        {
            if(s[i])
            {
                flag = true;
            }
            if(mod)
            {
                s[i] += 10;
            }
            if(s[i] & 1)
            {
                mod = 1;
            }
            else
            {
                mod = 0;
            }
            s[i] >>= 1;
        }
        if(mod)
        {
            matMul(mat[3], mat[1]);
        }
        matMul(mat[1], mat[1]);
    }
    vec[0][0] = v;
    vec[0][1] = 0;
    vec[0][2] = 1;
    matMul(vec[0], mat[3]);
    printf("%I64d\n", vec[0][1]);
}

void solve()
{
    int t;
    scanf("%d", &t);
    char s[200];
    while(t--)
    {
        scanf("%s", s);
        getResult(s);
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        printf("Case %d:\n", cas);
        getMat();
        solve();
    }
    return 0;
}

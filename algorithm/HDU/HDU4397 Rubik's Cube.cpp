#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 27;
const int MAXS = 205;
const int DIR_F = 0;
const int DIR_B = 1;
const int DIR_L = 2;
const int DIR_R = 3;
const int DIR_U = 4;
const int DIR_D = 5;

int pos[MAXN], dir[MAXN];

void init()
{
    for(int i=0; i<MAXN; ++i)
    {
        pos[i] = i;
        dir[i] = DIR_U;
    }
}

inline void rotate_left(const int &b1, const int &b2, const int &b3, const int &b4)
{
    int temp = pos[b1];
    pos[b1] = pos[b2];
    pos[b2] = pos[b3];
    pos[b3] = pos[b4];
    pos[b4] = temp;
    temp = dir[b1];
    dir[b1] = dir[b2];
    dir[b2] = dir[b3];
    dir[b3] = dir[b4];
    dir[b4] = temp;
}

inline void rotate_right(const int &b1, const int &b2, const int &b3, const int &b4)
{
    int temp = pos[b4];
    pos[b4] = pos[b3];
    pos[b3] = pos[b2];
    pos[b2] = pos[b1];
    pos[b1] = temp;
    temp = dir[b4];
    dir[b4] = dir[b3];
    dir[b3] = dir[b2];
    dir[b2] = dir[b1];
    dir[b1] = temp;
}

inline void rotate_dir_U(int &dir)
{
    switch(dir)
    {
    case DIR_F:
        dir = DIR_L;
        break;
    case DIR_L:
        dir = DIR_B;
        break;
    case DIR_B:
        dir = DIR_R;
        break;
    case DIR_R:
        dir = DIR_F;
        break;
    }
}

inline void rotate_dir_u(int &dir)
{
    switch(dir)
    {
    case DIR_F:
        dir = DIR_R;
        break;
    case DIR_R:
        dir = DIR_B;
        break;
    case DIR_B:
        dir = DIR_L;
        break;
    case DIR_L:
        dir = DIR_F;
        break;
    }
}

inline void rotate_dir_R(int &dir)
{
    switch(dir)
    {
    case DIR_L:
        dir = DIR_U;
        break;
    case DIR_U:
        dir = DIR_R;
        break;
    case DIR_R:
        dir = DIR_D;
        break;
    case DIR_D:
        dir = DIR_L;
        break;
    }
}

inline void rotate_dir_r(int &dir)
{
    switch(dir)
    {
    case DIR_L:
        dir = DIR_D;
        break;
    case DIR_D:
        dir = DIR_R;
        break;
    case DIR_R:
        dir = DIR_U;
        break;
    case DIR_U:
        dir = DIR_L;
        break;
    }
}

inline void rotate_dir_F(int &dir)
{
    switch(dir)
    {
    case DIR_F:
        dir = DIR_D;
        break;
    case DIR_D:
        dir = DIR_B;
        break;
    case DIR_B:
        dir = DIR_U;
        break;
    case DIR_U:
        dir = DIR_F;
        break;
    }
}

inline void rotate_dir_f(int &dir)
{
    switch(dir)
    {
    case DIR_F:
        dir = DIR_U;
        break;
    case DIR_U:
        dir = DIR_B;
        break;
    case DIR_B:
        dir = DIR_D;
        break;
    case DIR_D:
        dir = DIR_F;
        break;
    }
}

inline void rotate_dir(int d1, int d2, int d3, void (*rotate)(int &dir))
{
    rotate(dir[d1]);
    rotate(dir[d2]);
    rotate(dir[d3]);
}

inline void rotate_dir(int d1, int d2, int d3, int d4, int d5, int d6, int d7, int d8, int d9, void (*rotate)(int &dir))
{
    rotate_dir(d1, d2, d3, rotate);
    rotate_dir(d4, d5, d6, rotate);
    rotate_dir(d7, d8, d9, rotate);
}

bool judge()
{
    for(int i=0; i<MAXN; ++i)
    {
        if(pos[i] != i)
        {
            return false;
        }
        if(i == 4 || i == 10 || i == 12 || i == 24 || i == 16 || i ==22 || i == 13)
        {
            continue;
        }
        if(dir[i] != DIR_U)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    bool flag = false;
    char operation[MAXS];
    while(~scanf("%s", operation))
    {
        init();
        for(int i=0; operation[i]; ++i)
        {
            switch(operation[i])
            {
            case 'U':
                rotate_right(0, 2, 8, 6);
                rotate_right(1, 5, 7, 3);
                rotate_dir(0, 1, 2, 3, 4, 5, 6, 7, 8, rotate_dir_U);
                break;
            case 'u':
                rotate_left(0, 2, 8, 6);
                rotate_left(1, 5, 7, 3);
                rotate_dir(0, 1, 2, 3, 4, 5, 6, 7, 8, rotate_dir_u);
                break;
            case 'R':
                rotate_right(6, 8,  26, 24);
                rotate_right(7, 17, 25, 15);
                rotate_dir(6, 7, 8, 15, 16, 17, 24, 25, 26, rotate_dir_R);
                break;
            case 'r':
                rotate_left(6, 8,  26, 24);
                rotate_left(7, 17, 25, 15);
                rotate_dir(6, 7, 8, 15, 16, 17, 24, 25, 26, rotate_dir_r);
                break;
            case 'F':
                rotate_right(0, 6, 24, 18);
                rotate_right(3, 15, 21, 9);
                rotate_dir(0, 3, 6, 9, 12, 15, 18, 21, 24, rotate_dir_F);
                break;
            case 'f':
                rotate_left(0, 6, 24, 18);
                rotate_left(3, 15, 21, 9);
                rotate_dir(0, 3, 6, 9, 12, 15, 18, 21, 24, rotate_dir_f);
                break;
            case 'D':
                rotate_left(18, 20, 26, 24);
                rotate_left(19, 23, 25, 21);
                rotate_dir(18, 19, 20, 21, 22, 23, 24, 25, 26, rotate_dir_u);
                break;
            case 'd':
                rotate_right(18, 20, 26, 24);
                rotate_right(19, 23, 25, 21);
                rotate_dir(18, 19, 20, 21, 22, 23, 24, 25, 26, rotate_dir_U);
                break;
            case 'L':
                rotate_left(0, 2, 20, 18);
                rotate_left(1, 11, 19, 9);
                rotate_dir(0, 1, 2, 9, 10, 11, 18, 19, 20, rotate_dir_r);
                break;
            case 'l':
                rotate_right(0, 2, 20, 18);
                rotate_right(1, 11, 19, 9);
                rotate_dir(0, 1, 2, 9, 10, 11, 18, 19, 20, rotate_dir_R);
                break;
            case 'B':
                rotate_left(2, 8,  26, 20);
                rotate_left(5, 17, 23, 11);
                rotate_dir(2, 5, 8, 11, 14, 17, 20, 23, 26, rotate_dir_f);
                break;
            case 'b':
                rotate_right(2, 8,  26, 20);
                rotate_right(5, 17, 23, 11);
                rotate_dir(2, 5, 8, 11, 14, 17, 20, 23, 26, rotate_dir_F);
                break;
            case 'X':
                rotate_right(9,  11, 17, 15);
                rotate_right(10, 14, 16, 12);
                rotate_dir(9, 10, 11, 12, 13, 14, 15 ,16, 17, rotate_dir_U);
                break;
            case 'x':
                rotate_left(9,  11, 17, 15);
                rotate_left(10, 14, 16, 12);
                rotate_dir(9, 10, 11, 12, 13, 14, 15 ,16, 17, rotate_dir_u);
                break;
            case 'Y':
                rotate_right(3, 5,  23, 21);
                rotate_right(4, 14, 22, 12);
                rotate_dir(3, 4, 5, 12, 13, 14, 21, 22, 23, rotate_dir_R);
                break;
            case 'y':
                rotate_left(3, 5,  23, 21);
                rotate_left(4, 14, 22, 12);
                rotate_dir(3, 4, 5, 12, 13, 14, 21, 22, 23, rotate_dir_r);
                break;
            case 'Z':
                rotate_left(1, 7,  25, 19);
                rotate_left(4, 16, 22, 10);
                rotate_dir(1, 4, 7, 10, 13, 16, 19, 22, 25, rotate_dir_f);
                break;
            case 'z':
                rotate_right(1, 7,  25, 19);
                rotate_right(4, 16, 22, 10);
                rotate_dir(1, 4, 7, 10, 13, 16, 19, 22, 25, rotate_dir_F);
                break;
            }
        }
        if(flag)
        {
            printf("\n");
        }
        else
        {
            flag = true;
        }
        if(judge())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}

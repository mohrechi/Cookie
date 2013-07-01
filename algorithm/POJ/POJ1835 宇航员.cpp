#include<iostream>
#include<string.h>
using namespace std;
int x,y,z,p;
int bback[6]={3, 4, 5, 0, 1, 2};
int lleft[6][6]={{0, 2, 4, 0, 5, 1},{5, 0, 0, 2, 0, 3},{1, 3, 0, 4, 0, 0},{3, 5, 1, 3, 2, 4},{2, 3, 3, 5, 3, 0},{4, 0, 3, 1, 3, 3}};
int rright[6][6]={{3, 5, 1, 3, 2, 4},{2, 3, 3, 5, 3, 0},{4, 0, 3, 1, 3, 3},{0, 2, 4, 0, 5, 1},{5, 0, 0, 2, 0, 3},{1, 3, 0, 4, 0, 0}};
int uup[6][6][2]={{{0,3},{1,3},{2,3},{3,3},{4,3},{5,3}},{{0,4},{1,4},{2,4},{3,4},{4,4},{5,4}},{{0,5},{1,5},{2,5},{3,5},{4,5},{5,5}},{{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}},{{0,1},{1,1},{2,1},{3,1},{4,1},{5,1}},{{0,2},{1,2},{2,2},{3,2},{4,2},{5,2}}};
int ddown[6][6][2]={{{3,0},{4,0},{5,0},{0,0},{1,0},{2,0}},{{3,1},{4,1},{5,1},{0,1},{1,1},{2,1}},{{3,2},{4,2},{5,2},{0,2},{1,2},{2,2}},{{3,3},{4,3},{5,3},{0,3},{1,3},{2,3}},{{3,4},{4,4},{5,4},{0,4},{1,4},{2,4}},{{3,5},{4,5},{5,5},{0,5},{1,5},{2,5}}};

void walk(int step)
{
    switch (p)
    {
        case 0: x += step; break;
        case 1: y += step; break;
        case 2: z += step; break;
        case 3: x -= step; break;
        case 4: y -= step; break;
        case 5: z -= step; break;
    }
}

int main()
{
    int icase, n, step, head, tmp1, tmp2;
    char str[10];
    cin >> icase;
    while (icase--)
    {
        head = 2;
        x = y = z = p = 0;
        cin >> n;
        while (n--)
        {
             cin >> str >> step;
             if (strcmp("forward", str) == 0) ;
             if (strcmp("back", str) == 0) p = bback[p];
             if (strcmp("left", str) == 0) p = lleft[p][head];
             if (strcmp("right", str) == 0) p = rright[p][head];
             if (strcmp("up", str) == 0)
             {
                 tmp1 = uup[p][head][0];
                 tmp2 = uup[p][head][1];
                 p = tmp1;
                 head = tmp2;
             }
             if (strcmp("down", str) == 0)
             {
                 tmp1 = ddown[p][head][0];
                 tmp2 = ddown[p][head][1];
                 p = tmp1;
                 head = tmp2;
             }
             walk(step);
        }
        cout << x << ' ' << y << ' '<< z << ' ' << p << endl;
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ESP 1E-5

struct POINT{

    double x, y;

}A, B, C, D;

int P, Q, R;

POINT Get_Mid(POINT PL, POINT PR)
{
    POINT temp;
    temp.x = (PL.x + PR.x) / 2.0;
    temp.y = (PL.y + PR.y) / 2.0;
    return temp;
}

double len(POINT p1, POINT p2)
{
    return sqrt(ESP + (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double Get_Min_Time(POINT pt)
{
    POINT left = C, right = D, mid1, mid2;
    double mid1_area = 0, mid2_area = 1;
    while(fabs(mid2_area - mid1_area) > ESP)
    {
        mid1 = Get_Mid(left, right);
        mid2 = Get_Mid(mid1, right);
        mid1_area = len(pt, mid1) / R + len(mid1, D) / Q;
        mid2_area = len(pt, mid2) / R + len(mid2, D) / Q;
        if(mid1_area <= mid2_area) right = mid2;
        else left = mid1;
    }
    return mid1_area + len(A, pt) / P ;
}

int main()
{
    int CASE;
    POINT left, mid1, mid2, right;
    scanf("%d", &CASE);
    while(CASE --)
    {
       scanf("%lf %lf %lf %lf %lf %lf %lf %lf %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y, &D.x, &D.y, &P, &Q, &R);
       left = A;
       right = B;
       double mid1_area = 0, mid2_area = 1;
       while(fabs(mid1_area - mid2_area) > ESP)
       {
           mid1 = Get_Mid(left, right);
           mid2 = Get_Mid(mid1, right);
           mid1_area = Get_Min_Time(mid1);
           mid2_area = Get_Min_Time(mid2);
           if(mid1_area <= mid2_area) right = mid2;
           else left = mid1;
       }
       printf("%.2lf\n", mid1_area);
    }
    return 0;
}

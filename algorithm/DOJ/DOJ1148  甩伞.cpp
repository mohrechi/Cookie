#include<cstdio>
#include<cmath>

int main()
{
    int r, h, w;
    float t, s, x;
    while(~scanf("%d%d%d",&r,&h,&w))
    {
        t = sqrt(2 * h / 9.8);
        s = w * t * r;
        x = sqrt(s * s + r * r);
        x = (int)(x * 100 + 0.5);
        printf("%.2lf\n", x / 100.0);
    }
    return 0;
}

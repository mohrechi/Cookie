#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);

int main()
{
    double H, alpha, beta, gamma, phi, delta;
    while (~scanf("%lf%lf%lf%lf%lf%lf", &H, &alpha, &beta, &gamma, &phi, &delta))
    {
        alpha = alpha * PI / 180.0;
        beta = beta * PI / 180.0;
        phi = phi * PI / 180.0;
        delta = delta * PI / 180.0;
        double Ea = 0.5 * gamma * H * H *
            cos(phi - alpha) * cos(phi - alpha) /
            cos(alpha) / cos(alpha) / cos(alpha + delta) /
            (1.0 + sqrt(sin(phi + delta) * sin(phi - beta) / cos(delta + alpha) / cos(alpha - beta))) /
            (1.0 + sqrt(sin(phi + delta) * sin(phi - beta) / cos(delta + alpha) / cos(alpha - beta)));
        double Ep = 0.5 * gamma * H * H *
            cos(phi + alpha) * cos(phi + alpha) /
            cos(alpha) / cos(alpha) / cos(alpha - delta) /
            (1.0 - sqrt(sin(phi + delta) * sin(phi + beta) / cos(alpha - delta) / cos(alpha - beta))) /
            (1.0 - sqrt(sin(phi + delta) * sin(phi + beta) / cos(alpha - delta) / cos(alpha - beta)));
        printf("Ea=%.3lf Ep=%.3lf\n", Ea, Ep);
    }
    return 0;
}

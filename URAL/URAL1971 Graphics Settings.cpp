#include <bits/stdc++.h>
using namespace std;

inline void output(const double &sum, const double &p) {
    if (sum >= p - log(10.0)) {
        puts("Slideshow");
    } else if (sum <= p - log(60.0)) {
        puts("Perfect");
    } else {
        puts("So-so");
    }
}

int main() {
    int n, m;
    double W, H, k, p, res;
    char option[1024];
    map<string, double> ks;
    scanf("%d", &n);
    double sum = 0.0;
    while (n--) {
        scanf("%s%lf", option, &k);
        k = log(k);
        ks[option] = k;
        sum += k;
    }
    scanf("%lf%lf%lf", &W, &H, &p);
    p = log(p);
    res = log(W * H);
    sum += res;
    scanf("%d", &m);
    output(sum, p);
    while (m--) {
        scanf("%s", option);
        if (option[1] == 'n') {
            scanf("%s", option);
            sum += ks[option];
        } else if (option[1] == 'f') {
            scanf("%s", option);
            sum -= ks[option];
        } else {
            scanf("%lf%lf", &W, &H);
            sum -= res;
            res = log(W * H);
            sum += res;
        }
        output(sum, p);
    }
    return 0;
}

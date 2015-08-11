#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, s, q, ans = 1;
    scanf("%d%d%d", &t, &s, &q);
	while((s *= q) < t) {
        ++ans;
	}
	printf("%d\n", ans);
    return 0;
}

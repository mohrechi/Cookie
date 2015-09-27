#include <bits/stdc++.h>
using namespace std;

long long a[] = {3, 15, 81, 6723, 50625, 2562991875LL};
int sg[] = {0, 1, 2, 0, 3, 1, 2};

int main() {
    int n, ans = 0;
    long long x;
    cin >> n;
    while (n--) {
        cin >> x;
        ans ^= sg[lower_bound(a, a + 6, x) - a];
    }
    cout << (ans ? "Furlo" : "Rublo") << endl;
    return 0;
}

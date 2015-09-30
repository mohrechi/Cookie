#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, n, ar;
    cin >> V >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar;
        if (ar == V) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

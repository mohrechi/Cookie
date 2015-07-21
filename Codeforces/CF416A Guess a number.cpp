#include <bits/stdc++.h>
using namespace std;

int main() {
    string op, cond;
    int n, num, minBound = -2e9, maxBound = 2e9;
    cin >> n;
    while (n--) {
        cin >> op >> num >> cond;
        if (cond == "N") {
            op[0] = op[0] == '>' ? '<' : '>';
            if (op.size() == 2) {
                op.pop_back();
            } else {
                op.push_back('=');
            }
        }
        if (op[0] == '>') {
            minBound = max(minBound, num + (op.size() == 1));
        } else {
            maxBound = min(maxBound, num - (op.size() == 1));
        }
    }
    if (minBound <= maxBound) {
        cout << minBound << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}

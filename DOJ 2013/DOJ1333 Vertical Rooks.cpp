#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;

int t, n;
int x[MAXN], y;

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        int mex = 0;
        for (int i = 0; i < n; ++i) {
            cin >> y;
            mex ^= abs(x[i] - y) - 1;
        }
        if (mex == 0) {
            cout << "player-1" << endl;
        } else {
            cout << "player-2" << endl;
        }
    }
}

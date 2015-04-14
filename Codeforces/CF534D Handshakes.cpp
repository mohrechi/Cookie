#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    while (cin >> n) {
        vector<stack<int>> shakes(n + 1);
        vector<int> order;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            shakes[a].push(i);
        }
        int index = 0;
        int remain = n;
        while (index >= 0) {
            if (!shakes[index].empty()) {
                order.push_back(shakes[index].top());
                --remain;
                ++index;
            } else {
                if (index - 3 < 0) {
                    break;
                }
                shakes[index - 3].pop();
                shakes[index - 2].pop();
                shakes[index - 1].pop();
                index -= 3;
            }
        }
        if (remain == 0) {
            cout << "Possible" << endl;
            for (auto o : order) {
                cout << o << " ";
            }
            cout << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

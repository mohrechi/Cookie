#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<vector<int>> up = {
        {0, 8},
        {0, 1, 3, 4, 7, 8, 9},
        {2, 8},
        {3, 8, 9},
        {4, 8, 9},
        {5, 6, 8, 9},
        {6, 8},
        {0, 3, 7, 8, 9},
        {8},
        {8, 9}
    };
    while (cin >> x) {
        cout << up[x / 10].size() * up[x % 10].size() << endl;
    }
    return 0;
}

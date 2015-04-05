#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> white, black;
    white['Q'] = black['q'] = 9;
    white['R'] = black['r'] = 5;
    white['B'] = black['b'] = 3;
    white['N'] = black['n'] = 3;
    white['P'] = black['p'] = 1;
    string board;
    int sum1 = 0, sum2 = 0;
    while (cin >> board) {
        for (auto c : board) {
            sum1 += white[c];
            sum2 += black[c];
        }
    }
    if (sum1 > sum2) {
        cout << "White" << endl;
    } else if (sum1 < sum2) {
        cout << "Black" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}

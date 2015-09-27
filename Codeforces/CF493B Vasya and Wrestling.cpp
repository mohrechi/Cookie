#include <bits/stdc++.h>
using namespace std;

int compare(vector<int> &first, vector<int> &second) {
    for (int i = 0; i < (int)min(first.size(), second.size()); ++i) {
        if (first[i] > second[i]) {
            return 1;
        }
        if (first[i] < second[i]) {
            return -1;
        }
    }
    if (first.size() > second.size()) {
        return 1;
    }
    if (first.size() < second.size()) {
        return -1;
    }
    return 0;
}

int main() {
    int n, a;
    vector<int> first, second;
    long long sumF = 0, sumS = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a > 0) {
            first.push_back(a);
            sumF += a;
        } else {
            second.push_back(-a);
            sumS -= a;
        }
    }
    bool firstWin;
    if (sumF > sumS) {
        firstWin = true;
    } else if (sumF < sumS) {
        firstWin = false;
    } else {
        int c = compare(first, second);
        if (c != 0) {
            firstWin = c > 0;
        } else {
            firstWin = a > 0;
        }
    }
    cout << (firstWin ? "first" : "second") << endl;
    return 0;
}

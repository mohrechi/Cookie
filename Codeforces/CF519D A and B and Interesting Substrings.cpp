#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> x(26);
    string s;
    for (int i = 0; i < 26; ++i) {
        cin >> x[i];
    }
    cin >> s;
    vector<map<long long, int>> nums(26);
    long long ans = 0;
    long long sum = 0;
    for (auto c : s) {
        int v = c - 'a';
        ans += nums[v][sum];
        sum += x[v];
        ++nums[v][sum];
    }
    cout << ans << endl;
    return 0;
}

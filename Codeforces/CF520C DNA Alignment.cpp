#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        map<char, int> nums;
        for (auto c : s) {
            ++nums[c];
        }
        int maxNum = 0;
        for (auto i : nums) {
            maxNum = max(maxNum, i.second);
        }
        int m = 0;
        for (auto i : nums) {
            if (maxNum == i.second) {
                ++m;
            }
        }
        long long ans = 1;
        while (n--) {
            ans = ans * m % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}

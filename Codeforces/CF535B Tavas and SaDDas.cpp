#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9 + 10;

int main() {
    set<int> nums;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j < (1 << i); ++j) {
            int num = 0;
            for (int k = 0; k < i; ++k) {
                num = num * 10 + ((j & (1 << k)) ? 4 : 7);
            }
            nums.insert(num);
        }
    }
    int index = 0;
    map<int, int> indexes;
    for (auto num : nums) {
        indexes[num] = ++index;
    }
    int n;
    while (cin >> n) {
        cout << indexes[n] << endl;
    }
    return 0;
}

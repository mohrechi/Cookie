#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums;
        while (n) {
            int num = 0;
            int base = 1;
            int temp = n;
            while (temp) {
                if (temp % 10) {
                    num += base;
                }
                temp /= 10;
                base *= 10;
            }
            n -= num;
            nums.push_back(num);
        }
        cout << nums.size() << endl;
        for (auto num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

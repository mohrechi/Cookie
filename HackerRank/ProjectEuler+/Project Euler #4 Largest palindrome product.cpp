#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    int temp = num;
    int rev = 0;
    while (temp) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    return num == rev;
}

int main() {
    int T, N;
    set<int, greater<int>> pals;
    for (int i = 100; i <= 999; ++i) {
        for (int j = 100; j <= 999; ++j) {
            int p = i * j;
            if (isPalindrome(p)) {
                pals.insert(p);
            }
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << *pals.upper_bound(N) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

bool isPrime[MAXN];
int prime[MAXN], primeNum;

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXN; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXN; i += 2) {
        int inc = i << 1;
        for (int j = i + inc; j < MAXN; j += inc) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i < MAXN; ++i) {
        if (isPrime[i]) {
            prime[primeNum++] = i;
        }
    }
}

int main() {
    int T, N;
    map<int, long long> nums;
    long long num = 0;
    initPrime();
    for (int i = 1; ; ++i) {
        num += i;
        long long cnt = 1, temp = num;
        for (int j = 0; j < primeNum and prime[j] <= temp; ++j) {
            if (temp % prime[j] == 0) {
                int c = 0;
                while (temp % prime[j] == 0) {
                    temp /= prime[j];
                    ++c;
                }
                cnt *= c + 1;
            }
        }
        if (temp > 1) {
            cnt *= 2;
        }
        for (int j = cnt; j >= 1; --j) {
            if (nums.find(j) == nums.end()) {
                nums[j] = num;
            } else {
                break;
            }
        }
        if (cnt >= 1000) {
            break;
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << nums[N + 1] << endl;
    }
    return 0;
}

#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, b;
    while (scanf("%d", &n) != EOF) {
        multiset<long long> boards;
        while (n--) {
            scanf("%d", &b);
            boards.insert(b);
        }
        long long sum = 0;
        while (boards.size() > 1) {
            long long a = *boards.begin();
            boards.erase(boards.begin());
            long long b = *boards.begin();
            boards.erase(boards.begin());
            sum += a + b;
            boards.insert(a + b);
        }
        cout << sum << endl;
    }
    return 0;
}

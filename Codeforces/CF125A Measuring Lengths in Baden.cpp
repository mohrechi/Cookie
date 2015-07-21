#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    ++n;
    int a = n / 36;
    int b = n / 3 % 12;
    cout << a << " " << b << endl;
    return 0;
}

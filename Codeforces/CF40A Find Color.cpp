#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int r2 = x * x + y * y;
    int r = sqrt(r2);
    if (r * r < r2 and (r + 1) * (r + 1) > r2 and ((r % 2 and x * y > 0) or (r % 2 == 0 and x * y < 0))) {
        cout << "white" << endl;
    } else {
        cout << "black" << endl;
    }
    return 0;
}

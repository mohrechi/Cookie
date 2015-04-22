#include <bits/stdc++.h>
using namespace std;

int main() {
    long long C, Hr, Hb, Wr, Wb;
    while (cin >> C >> Hr >> Hb >> Wr >> Wb) {
        long long ans = 0;
        int sq = sqrt((double)C);
        if (max(Wr, Wb) > sq) {
            if (Wr > Wb) {
                swap(Wr, Wb);
                swap(Hr, Hb);
            }
            for (int i = 0; i * Wb <= C; ++i) {
                ans = max(ans, i * Hb + (C - i * Wb) / Wr * Hr);
            }
        } else {
            if (Hb * Wr > Wb * Hr) {
                swap(Wr, Wb);
                swap(Hr, Hb);
            }
            for (int i = 0; i <= sq; ++i) {
                ans = max(ans, i * Hb + (C - i * Wb) / Wr * Hr);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

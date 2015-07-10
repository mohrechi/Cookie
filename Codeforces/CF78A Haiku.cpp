#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[101];
    int num[3] = {5, 7, 5};
    bool valid = true;
    for (int i = 0; i < 3; ++i) {
        int n = 0;
        cin.getline(ch, sizeof(ch) / sizeof(ch[0]));
        for (int j = 0; ch[j] != 0; ++j) {
            if (ch[j] == 'a' || ch[j] == 'e' || ch[j] == 'i' || ch[j] == 'o' || ch[j] == 'u') {
                ++n;
            }
        }
        if (n != num[i]) {
            valid = false;
        }
    }
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}

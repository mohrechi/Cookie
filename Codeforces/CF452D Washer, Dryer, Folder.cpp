#include <bits/stdc++.h>
using namespace std;

int main() {
    int k1, k2, k3, n1, n2, n3, t1, t2, t3;
    cin >> k1;
    k2 = k3 = 0;
    cin >> n1 >> n2 >> n3;
    cin >> t1 >> t2 >> t3;
    multiset<int> washers, dryers, folders;
    int w1, w2, w3;
    w1 = w2 = w3 = 0;
    int current = 0;
    while (true) {
        if (k1 && w1 < n1) {
            --k1, ++w1;
            washers.insert(current + t1);
            continue;
        }
        if (k2 && w2 < n2) {
            --k2, ++w2;
            dryers.insert(current + t2);
            continue;
        }
        if (k3 && w3 < n3) {
            --k3, ++w3;
            folders.insert(current + t3);
            continue;
        }
        if (washers.size()) {
            if (dryers.size() == 0 || *washers.begin() <= *dryers.begin()) {
                if (folders.size() == 0 || *washers.begin() <= *folders.begin()) {
                    current = *washers.begin();
                    washers.erase(washers.begin());
                    ++k2, --w1;
                    continue;
                }
            }
        }
        if (dryers.size()) {
            if (folders.size() == 0 || *dryers.begin() <= *folders.begin()) {
                current = *dryers.begin();
                dryers.erase(dryers.begin());
                ++k3, --w2;
                continue;
            }
        }
        if (folders.size()) {
            current = *folders.begin();
            folders.erase(folders.begin());
            --w3;
            continue;
        }
        break;
    }
    cout << current << endl;
    return 0;
}

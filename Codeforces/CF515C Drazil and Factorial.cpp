#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a;
    while (cin >> n >> a) {
        multiset<int, greater<int>> digits;
        for (auto d : a) {
            switch (d) {
            case '2':
                digits.insert(2);
                break;
            case '3':
                digits.insert(3);
                break;
            case '4':
                digits.insert(2);
                digits.insert(2);
                digits.insert(3);
                break;
            case '5':
                digits.insert(5);
                break;
            case '6':
                digits.insert(3);
                digits.insert(5);
                break;
            case '7':
                digits.insert(7);
                break;
            case '8':
                digits.insert(2);
                digits.insert(2);
                digits.insert(2);
                digits.insert(7);
                break;
            case '9':
                digits.insert(2);
                digits.insert(3);
                digits.insert(3);
                digits.insert(7);
                break;
            }
        }
        for (auto d : digits) {
            cout << d;
        }
        cout << endl;
    }
    return 0;
}

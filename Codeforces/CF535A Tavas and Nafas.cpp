#include <bits/stdc++.h>
using namespace std;

void print1(int num) {
    switch (num) {
    case 0:
        cout << "zero";
        break;
    case 1:
        cout << "one";
        break;
    case 2:
        cout << "two";
        break;
    case 3:
        cout << "three";
        break;
    case 4:
        cout << "four";
        break;
    case 5:
        cout << "five";
        break;
    case 6:
        cout << "six";
        break;
    case 7:
        cout << "seven";
        break;
    case 8:
        cout << "eight";
        break;
    case 9:
        cout << "nine";
        break;
    }
}

void print2(int num) {
    switch (num) {
    case 1:
        cout << "ten";
        break;
    case 2:
        cout << "twenty";
        break;
    case 3:
        cout << "thirty";
        break;
    case 4:
        cout << "forty";
        break;
    case 5:
        cout << "fifty";
        break;
    case 6:
        cout << "sixty";
        break;
    case 7:
        cout << "seventy";
        break;
    case 8:
        cout << "eighty";
        break;
    case 9:
        cout << "ninety";
        break;
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n < 10) {
            print1(n);
        } else if (n % 10 == 0) {
            print2(n / 10);
        } else if (n < 20) {
            switch (n) {
            case 11:
                cout << "eleven";
                break;
            case 12:
                cout << "twelve";
                break;
            case 13:
                cout << "thirteen";
                break;
            case 14:
                cout << "fourteen";
                break;
            case 15:
                cout << "fifteen";
                break;
            case 16:
                cout << "sixteen";
                break;
            case 17:
                cout << "seventeen";
                break;
            case 18:
                cout << "eighteen";
                break;
            case 19:
                cout << "nineteen";
                break;
            }
        } else {
            print2(n / 10);
            cout << "-";
            print1(n % 10);
        }
        cout << endl;
    }
    return 0;
}

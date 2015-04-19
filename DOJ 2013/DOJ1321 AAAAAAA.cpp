#include <bits/stdc++.h>
using namespace std;

int main() {
    char c;
    while (~scanf("%c", &c))
        putchar(('a' <= c && c <= 'z') ? c - 'a' + 'A' : c);
    return 0;
}

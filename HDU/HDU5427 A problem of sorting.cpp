#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 5;

int n;
struct Node {
    string name;
    int year;
    inline void input() {
        getline(cin, name);
        int n = name.length();
        year = 0;
        for (int i = n - 4; i < n; ++i) {
            year = year * 10 + name[i] - '0';
        }
    }
    bool operator <(const Node &node) const {
        return year > node.year;
    }
    inline void output() {
        for (int i = 0; i < (int)name.length() - 5; ++i) {
            putchar(name[i]);
        }
        putchar('\n');
    }
} node[MAXN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; ++i) {
            node[i].input();
        }
        sort(node, node + n);
        for (int i = 0; i < n; ++i) {
            node[i].output();
        }
    }
    return 0;
}

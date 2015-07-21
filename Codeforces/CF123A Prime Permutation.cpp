#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

char s[MAXN];
int parent[MAXN], num[MAXN];

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        num[i] = 1;
    }
}

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void combine(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        num[x] += num[y];
        parent[y] = x;
    }
}

struct Node {
    int num, val;
    bool operator <(const Node &node) const {
        return num < node.num;
    }
} chars[26];

int main() {
    int n;
    gets(s);
    for (int i = 0; i < 26; ++i) {
        chars[i].val = 'a' + i;
    }
    for (n = 0; s[n]; ++n) {
        ++chars[s[n] - 'a'].num;
    }
    init(n);
    for (int i = 2; i <= n; ++i) {
        if (find(i) == i) {
            for (int j = i + i; j <= n; j += i) {
                combine(i, j);
            }
        }
    }
    vector<Node> clusters;
    for (int i = 1; i <= n; ++i) {
        if (find(i) == i) {
            clusters.push_back({num[find(i)], i});
        }
    }
    sort(chars, chars + 26);
    sort(clusters.begin(), clusters.end());
    bool possible = true;
    int idx = 0;
    for (auto cluster : clusters) {
        while (chars[idx].num == 0) {
            if (++idx >= 26) {
                possible = false;
                break;
            }
        }
        if (cluster.num > chars[idx].num) {
            possible = false;
            break;
        }
        for (int i = 1; i <= n; ++i) {
            if (find(i) == cluster.val) {
                s[i - 1] = chars[idx].val;
            }
        }
        chars[idx].num -= cluster.num;
    }
    if (possible) {
        puts("YES");
        puts(s);
    } else {
        puts("NO");
    }
    return 0;
}

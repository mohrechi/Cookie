#include <bits/stdc++.h>
using namespace std;
const int MAXN = 729000 + 100;
const int MAXM = 500000 + 100;

int n, m, ans;
int match[MAXN], matchNum;
char buffer[MAXM * 4];
int values[MAXM];

inline int getIndex(const char* word) {
    int index = 0;
    for (int i = 0; i < 3; ++i) {
        index = index * 90 + word[i] - 33;
    }
    return index;
}

inline void add(int index) {
    if (match[index] == 0) {
        --matchNum;
    } else if (match[index] == -1) {
        ++matchNum;
    }
    ++match[index];
}

inline void sub(int index) {
    if (match[index] == 0) {
        --matchNum;
    } else if (match[index] == 1) {
        ++matchNum;
    }
    --match[index];
}

int main() {
    gets(buffer);
    for (int i = 0; i - 1 < 0 || buffer[i - 1]; i += 4, ++n) {
        sub(getIndex(buffer + i));
    }
    gets(buffer);
    for (int i = 0; i - 1 < 0 || buffer[i - 1]; i += 4, ++m) {
        values[m] = getIndex(buffer + i);
        add(values[m]);
        if (m - n >= 0) {
            sub(values[m - n]);
        }
        if (matchNum == 0) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}

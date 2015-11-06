#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, t;
char s1[MAXN], s2[MAXN], s[MAXN];

char getDiffChar(char a, char b) {
    if (a != 'a' && b != 'a') {
        return 'a';
    }
    if (a != 'b' && b != 'b') {
        return 'b';
    }
    return 'c';
}

int main() {
    scanf("%d%d", &n, &t);
    scanf("%s%s", s1, s2);
    int same = 0;
    for (int i = 0; i < n; ++i) {
        same += s1[i] == s2[i];
    }
    int diff = n - same;
    if (diff > t * 2) {
        puts("-1");
    } else {
        if (t >= diff) {
            int change = t - diff;
            for (int i = 0; i < n; ++i) {
                if (s1[i] == s2[i]) {
                    if (change) {
                        --change;
                        s[i] = s1[i] != 'a' ? 'a' : 'b';
                    } else {
                        s[i] = s1[i];
                    }
                } else {
                    s[i] = getDiffChar(s1[i], s2[i]);
                }
            }
        } else {
            int change1 = diff - t, change2 = diff - t;
            for (int i = 0; i < n; ++i) {
                if (s1[i] == s2[i]) {
                    s[i] = s1[i];
                } else {
                    if (change1) {
                        --change1;
                        s[i] = s1[i];
                    } else {
                        if (change2) {
                            --change2;
                            s[i] = s2[i];
                        } else {
                            s[i] = getDiffChar(s1[i], s2[i]);
                        }
                    }
                }
            }
        }
        s[n] = 0;
        puts(s);
    }
    return 0;
}

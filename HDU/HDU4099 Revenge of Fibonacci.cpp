#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int INC = 1000000000;

struct BigInteger {
    int data[2500];
    int len;
    BigInteger() {
        len = 1;
        data[0] = 0;
    }
    BigInteger(int x) {
        len = 1;
        data[0] = x;
    }
};

void add(const BigInteger &a, const BigInteger &b, BigInteger &c) {
    if (a.len > b.len) {
        add(b, a, c);
    } else {
        bool carry = false;
        for (int i = 0; i < a.len; ++i) {
            c.data[i] = carry + a.data[i] + b.data[i];
            if (c.data[i] >= INC) {
                c.data[i] -= INC;
                carry = true;
            } else {
                carry = false;
            }
        }
        for (int i = a.len; i < b.len; ++i) {
            c.data[i] = carry + b.data[i];
            if (c.data[i] >= INC) {
                c.data[i] -= INC;
                carry = true;
            } else {
                carry = false;
            }
        }
        if (carry) {
            c.len = b.len + 1;
            c.data[b.len] = 1;
        } else {
            c.len = b.len;
        }
    }
}

char s[100], tmp[100];

void toTmpStr(int x) {
    for (int i = 0; i < 9; ++i) {
        tmp[8 - i] = x % 10;
        x /= 10;
    }
}

void toStr(const BigInteger &num) {
    int k = 0;
    for (int i = num.len - 1; i >= 0; --i) {
        toTmpStr(num.data[i]);
        if (i == num.len - 1) {
            int j;
            for (j = 0; j < 8 && tmp[j] == 0; ++j);
            for (; j < 9; ++j) {
                s[k++] = tmp[j];
            }
        } else {
            for (int j = 0; j < 9; ++j) {
                s[k++] = tmp[j];
            }
        }
        if (k > 40) {
            break;
        }
    }
    s[min(k, 40)] = -1;
}

struct TrieNode {
    int next[10];
    int minIdx;
    void clear() {
        minIdx = -1;
        memset(next, -1, sizeof(next));
    }
} trie[MAXN * 50];
int nodeNum;

void clearTrie() {
    nodeNum = 1;
    trie[0].clear();
}

inline int addNode() {
    trie[nodeNum].clear();
    return nodeNum++;
}

void addWord(int x, const char *s, int idx) {
    if (trie[x].minIdx == -1 || trie[x].minIdx > idx) {
        trie[x].minIdx = idx;
    }
    if (*s == -1) {
        return;
    }
    if (trie[x].next[(int)*s] == -1) {
        trie[x].next[(int)*s] = addNode();
    }
    addWord(trie[x].next[(int)*s], s + 1, idx);
}

int query(int x, const char *s) {
    if (*s == 0) {
        return trie[x].minIdx;
    }
    if (trie[x].next[*s - '0'] == -1) {
        return -1;
    }
    return query(trie[x].next[*s - '0'], s + 1);
}

int main() {
    BigInteger a(1), b(1), c;
    BigInteger *pa = &a;
    BigInteger *pb = &b;
    clearTrie();
    toStr(a);
    addWord(0, s, 0);
    toStr(b);
    addWord(0, s, 1);
    BigInteger *pc = &c;
    for (int i = 2; i < 100000; ++i) {
        add(*pa, *pb, *pc);
        toStr(*pc);
        addWord(0, s, i);
        BigInteger *pt = pa;
        pa = pb;
        pb = pc;
        pc = pt;
    }
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%s", s);
        printf("Case #%d: %d\n", t, query(0, s));
    }
    return 0;
}

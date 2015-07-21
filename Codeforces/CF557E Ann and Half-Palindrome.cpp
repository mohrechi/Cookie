#include <bits/stdc++.h>
using namespace std;
const int MAXS = 5000 + 10;

int n, k;
char s[MAXS];

bool palin[MAXS][MAXS];

struct TrieNode {
    TrieNode *next[2];
    int sum;
    TrieNode() {
        next[0] = next[1] = nullptr;
        sum = 0;
    }
} head;

inline int leftNum(TrieNode *node) {
    if (node->next[0] == nullptr) {
        return 0;
    }
    return node->next[0]->sum;
}

inline int rightNum(TrieNode *node) {
    if (node->next[1] == nullptr) {
        return 0;
    }
    return node->next[1]->sum;
}

void addWord(TrieNode *node, const char *s, int i, int j) {
    if (i <= j and palin[i][j]) {
        ++node->sum;
    }
    if (*s) {
        int next = *s == 'b';
        if (node->next[next] == nullptr) {
            node->next[next] = new TrieNode();
        }
        addWord(node->next[next], s + 1, i, j + 1);
    }
}

void pushUp(TrieNode *node) {
    if (node == nullptr) {
        return;
    }
    pushUp(node->next[0]);
    pushUp(node->next[1]);
    node->sum += leftNum(node) + rightNum(node);
}

void query(TrieNode *node, int i, int k) {
    int leftNum = 0, rightNum = 0;
    if (node->next[0] != nullptr) {
        leftNum = node->next[0]->sum;
    }
    if (node->next[1] != nullptr) {
        rightNum = node->next[1]->sum;
    }
    int nodeNum = node->sum - leftNum - rightNum;
    k -= nodeNum;
    if (nodeNum and k <= 0) {
        s[i] = 0;
        return;
    }
    if (k <= leftNum) {
        s[i] = 'a';
        query(node->next[0], i + 1, k);
    } else {
        s[i] = 'b';
        query(node->next[1], i + 1, k - leftNum);
    }
}

int main() {
    gets(s);
    scanf("%d", &k);
    n = strlen(s);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i + j < n; ++i) {
            if (s[i] == s[i + j]) {
                if (j <= 3 or palin[i + 2][i + j - 2]) {
                    palin[i][i + j] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        addWord(&head, s + i, i, i - 1);
    }
    pushUp(&head);
    query(&head, 0, k);
    puts(s);
    return 0;
}

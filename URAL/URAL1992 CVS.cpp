#include <stdio.h>
using namespace std;
const int MAXN = 5e5 + 10;

int n, m;

struct Node {
    int value;
    Node* prev;
} node[MAXN];
int nodeNum;

struct Head {
    Node* index;
    Node* history;
} head[MAXN];
int headNum;

void init() {
    head[1].index = nullptr;
    head[1].history = nullptr;
    nodeNum = 0;
    headNum = 2;
}

inline Node* create(int value, Node* prev) {
    Node* newNode = &node[nodeNum++];
    newNode->value = value;
    newNode->prev = prev;
    return newNode;
}

inline void learn(int c, int p) {
    head[c].index = create(p, head[c].index);
    head[c].history = nullptr;
}

inline void rollback(int c) {
    head[c].history = create(head[c].index->value, head[c].history);
    head[c].index = head[c].index->prev;
}

inline void relearn(int c) {
    head[c].index = create(head[c].history->value, head[c].index);
    head[c].history = head[c].history->prev;
}

inline void clone(int c) {
    head[headNum++] = head[c];
}

inline void check(int c) {
    if (head[c].index != nullptr) {
        printf("%d\n", head[c].index->value);
    } else {
        puts("basic");
    }
}

int main() {
    int c, p;
    char operation[100];
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d", operation, &c);
        switch (operation[0]) {
        case 'l':
            scanf("%d", &p);
            learn(c, p);
            break;
        case 'r':
            if (operation[1] == 'o') {
                rollback(c);
            } else {
                relearn(c);
            }
            break;
        case 'c':
            if (operation[1] == 'l') {
                clone(c);
            } else {
                check(c);
            }
            break;
        }
    }
    return 0;
}

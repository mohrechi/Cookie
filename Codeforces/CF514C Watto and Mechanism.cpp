#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int MAXM = 3e5 + 10;
const int MAXK = 6e5 + 10;

char buffer[MAXK];

class Trie {
public:
    Trie() {
        head = new Node();
    }

    void insert(const char *buffer) {
        insert(head, buffer);
    }

    bool query(const char *buffer) {
        return query(head, buffer, false);
    }
private:
    struct Node {
        Node* next[3];
        bool word;

        Node() {
            next[0] = next[1] = next[2] = nullptr;
            word = false;
        }
    };
    Node* head;

    void insert(Node* node, const char *buffer) {
        if (*buffer == 0) {
            node->word = true;
            return;
        }
        int c = (*buffer) - 'a';
        if (node->next[c] == nullptr) {
            node->next[c] = new Node();
        }
        insert(node->next[c], buffer + 1);
    }

    bool query(Node* node, const char *buffer, bool change) {
        if (*buffer == 0) {
            if (node->word && change) {
                return true;
            }
            return false;
        }
        int c = (*buffer) - 'a';
        for (int i = 0; i < 3; ++i) {
            if (node->next[i] != nullptr) {
                if (i == c) {
                    if (query(node->next[i], buffer + 1, change)) {
                        return true;
                    }
                } else {
                    if (!change) {
                        if (query(node->next[i], buffer + 1, true)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
} trie;

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) {
        scanf("%s", buffer);
        trie.insert(buffer);
    }
    while (m--) {
        scanf("%s", buffer);
        puts(trie.query(buffer) ? "YES" : "NO");
    }
    return 0;
}

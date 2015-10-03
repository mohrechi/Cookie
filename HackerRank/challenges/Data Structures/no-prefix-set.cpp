#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    bool isWord = false;
    TrieNode* next[26] = {};
};

bool addWord(TrieNode* node, const char* s, bool newPath) {
    if (node->isWord) {
        return false;
    }
    if (*s == 0) {
        if (!newPath) {
            return false;
        }
        node->isWord = true;
        return true;
    }
    int next = *s - 'a';
    if (node->next[next] == nullptr) {
        node->next[next] = new TrieNode();
        return addWord(node->next[next], s + 1, true);
    }
    return addWord(node->next[next], s + 1, newPath);
}

int main() {
    int n;
    char word[70];
    TrieNode* root = new TrieNode();
    scanf("%d", &n);
    while (n--) {
        scanf("%s", word);
        if (!addWord(root, word, false)) {
            puts("BAD SET");
            puts(word);
            return 0;
        }
    }
    puts("GOOD SET");
    return 0;
}

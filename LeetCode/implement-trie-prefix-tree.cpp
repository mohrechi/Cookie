class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
    bool isWord;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        insert(root, s, 0);
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* node = search(root, key, 0);
        return node == nullptr ? false : node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return search(root, prefix, 0) != nullptr;
    }

private:
    TrieNode* root;
    
    void insert(TrieNode* node, const string& s, int index) {
        if (index == (int)s.length()) {
            node->isWord = true;
            return;
        }
        int next = s[index] - 'a';
        if (node->next[next] == nullptr) {
            node->next[next] = new TrieNode();
        }
        insert(node->next[next], s, index + 1);
    }
    
    TrieNode* search(TrieNode* node, const string& s, int index) {
        if (index == (int)s.length()) {
            return node;
        }
        int next = s[index] - 'a';
        if (node->next[next] == nullptr) {
            return nullptr;
        }
        return search(node->next[next], s, index + 1);
    }
};

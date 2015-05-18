class WordDictionary {
public:
    void addWord(string word) {
        addWord(&head, word, 0);
    }

    bool search(string word) {
        return search(&head, word, 0);
    }

private:
    struct Node {
        bool isWord;
        Node *next[26];
        Node() {
            isWord = false;
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    } head;

    void addWord(Node* node, const string& word, int index) {
        if (index == (int)word.length()) {
            node->isWord = true;
        } else {
            int next = word[index] - 'a';
            if (node->next[next] == nullptr) {
                node->next[next] = new Node();
            }
            addWord(node->next[next], word, index + 1);
        }
    }

    bool search(Node* node, const string& word, int index) {
        if (index == (int)word.length()) {
            return node->isWord;
        }
        if (word[index] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->next[i] != nullptr) {
                    if (search(node->next[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            return false;
        }
        int next = word[index] - 'a';
        if (node->next[next] == nullptr) {
            return false;
        }
        return search(node->next[next], word, index + 1);
    }
};
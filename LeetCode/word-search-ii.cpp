const int STEP_X[] = {0, 1, 0, -1};
const int STEP_Y[] = {1, 0, -1, 0};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        if (row == 0) {
            return vector<string>();
        }
        col = board[0].size();
        if (col == 0) {
            return vector<string>();
        }
        for (int i = 0; i < words.size(); ++i) {
            trie.addWord(words[i], i);
        }
        this->board = board;
        this->words = words;
        this->visit = vector<vector<bool>>(row, vector<bool>(col, false));
        appear = vector<bool>(words.size(), false);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                visit[i][j] = true;
                search(i, j, trie.getNext(trie.getHead(), board[i][j]));
                visit[i][j] = false;
            }
        }
        return ans;
    }
private:
    int row, col;
    vector<string> ans;
    vector<vector<char>> board;
    vector<string> words;
    vector<vector<bool>> visit;
    vector<bool> appear;
    class Trie {
    public:
        struct Node {
            int id;
            Node* next[26];
            Node() {
                id = -1;
                for (int i = 0; i < 26; ++i) {
                    next[i] = nullptr;
                }
            }
        };
        Trie() {
            head = new Node();
        }
        inline void addWord(const string &word, int id) {
            addWord(head, word, 0, id);
        }
        inline Node* getHead() const {
            return head;
        }
        inline Node* getNext(Node* node, char ch) {
            return node->next[ch - 'a'];
        }
    private:
        Node* head;
        vector<Node*> nodes;
        void addWord(Node* node, const string &word, int idx, int id) {
            if (idx == (int)word.length()) {
                node->id = id;
            } else {
                int next = word[idx] - 'a';
                if (node->next[next] == nullptr) {
                    node->next[next] = new Node();
                }
                addWord(node->next[next], word, idx + 1, id);
            }
        }
    } trie;

    void search(int r, int c, Trie::Node* node) {
        if (node == nullptr) {
            return;
        }
        if (node->id != -1) {
            if (not appear[node->id]) {
                ans.push_back(words[node->id]);
            }
            appear[node->id] = true;
        }
        for (int k = 0; k < 4; ++k) {
            int tr = r + STEP_X[k];
            int tc = c + STEP_Y[k];
            if (0 <= tr and tr < row) {
                if (0 <= tc and tc < col) {
                    if (not visit[tr][tc]) {
                        visit[tr][tc] = true;
                        search(tr, tc, trie.getNext(node, board[tr][tc]));
                        visit[tr][tc] = false;
                    }
                }
            }
        }
    }
};

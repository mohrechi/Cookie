class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        s = "";
        for (int i = words.size() - 1; i >= 0; --i) {
            if (i <= (int)words.size() - 2) {
                s += " ";
            }
            s += words[i];
        }
    }
};

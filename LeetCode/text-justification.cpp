#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int index = 0;
        while (index < words.size()) {
            int start = index;
            int word_cnt = 0;
            int char_cnt = 0;
            for (; index < words.size(); ++index) {
                word_cnt += 1;
                char_cnt += words[index].length();
                if (char_cnt + word_cnt - 1 > L) {
                    word_cnt -= 1;
                    char_cnt -= words[index].length();
                    break;
                }
            }
            vector<int> spaces(word_cnt, 1);
            *spaces.rbegin() = 0;
            if (index != words.size()) {
                int total = char_cnt + word_cnt - 1;
                while (word_cnt > 1 && total < L) {
                    for (int i = 0; i < word_cnt - 1; ++i) {
                        spaces[i] += 1;
                        if (++total >= L) {
                            break;
                        }
                    }
                }
            }
            string line;
            for (int i = start; i < index; ++i) {
                line += words[i];
                while (spaces[i - start]--) {
                    line += ' ';
                }
            }
            while (line.size() < L) {
                line += ' ';
            }
            ret.push_back(line);
        }
        return ret;
    }
};

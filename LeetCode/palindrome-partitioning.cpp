#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        vector<int> partitions = {0};
        partition(s, palindromes, partitions);
        return palindromes;
    }
private:
    bool isPalindrome(string &s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s[i] != s[s.length() - i - 1]) {
                return false;
            }
        }
        return true;
    }
    void partition(string &s, vector<vector<string>> &palindromes, vector<int> partitions) {
        if (partitions[partitions.size() - 1] == s.length()) {
            palindromes.push_back(vector<string>());
            for (int i = 0; i < partitions.size() - 1; ++i) {
                palindromes[palindromes.size() - 1].push_back(s.substr(partitions[i], partitions[i + 1] - partitions[i]));
            }
            return;
        }
        int last = partitions[partitions.size() - 1];
        for (int i = last + 1; i <= s.size(); ++i) {
            string sub = s.substr(last, i - last);
            if (isPalindrome(sub)) {
                partitions.push_back(i);
                partition(s, palindromes, partitions);
                partitions.pop_back();
            }
        }
    }
};
int main()
{
    Solution sol;
    vector<vector<string>> res = sol.partition("aabbabaa");
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

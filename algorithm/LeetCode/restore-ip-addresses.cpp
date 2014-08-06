class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> ip;
        dfs(s, 0, ip, result);
        return result;
    }
private:
    void dfs(string &s, int index, vector<string> &ip, vector<string> &result) {
        if (index == s.length() && ip.size() == 4) {
            result.push_back(ip[0] + "." + ip[1] + "." + ip[2] + "." + ip[3]);
            return;
        }
        if (ip.size() > 0) {
            string last = ip[ip.size() - 1];
            if (last != "0") {
                ip[ip.size() - 1] += s[index];
                if (parseInt(ip[ip.size() - 1]) < 256) {
                    dfs(s, index + 1, ip, result);
                }
                ip[ip.size() - 1] = last;
            }
        }
        if (ip.size() < 4) {
            ip.push_back(string() + s[index]);
            dfs(s, index + 1, ip, result);
            ip.pop_back();
        }
    }
    int parseInt(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res = res * 10 + s[i] - '0';
        }
        return res;
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> subs;
        int last = 0;
        path += "/";
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (i - last > 0) {
                    string sub = path.substr(last, i - last);
                    if (sub != ".") {
                        if (sub == "..") {
                            if (subs.size() > 0) {
                                subs.pop_back();
                            }
                        } else {
                            subs.push_back(sub);
                        }
                    }
                }
                last = i + 1;
            }
        }
        string simplified = "/";
        for (int i = 0; i < subs.size(); ++i) {
            if (i) {
                simplified += "/";
            }
            simplified += subs[i];
        }
        return simplified;
    }
};

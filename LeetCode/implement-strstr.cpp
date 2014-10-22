class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int la = strlen(haystack);
        int lb = strlen(needle);
        if (la < lb) {
            return NULL;
        }
        if (lb == 0) {
            return haystack;
        }
        vector<int> next(lb + 1);
        int i = 0, j = -1;
        next[0] = -1;
        while (i < lb) {
            if (j == -1) {
                ++i, ++j;
                next[i] = j;
            } else if (needle[i] == needle[j]) {
                ++i, ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        i = 0, j = 0;
        while (i < la && j < lb) {
            if (j == -1) {
                ++i, ++j;
            } else if (haystack[i] == needle[j]) {
                ++i, ++j;
            } else {
                j = next[j];
            }
        }
        if (j >= lb) {
            return &haystack[i - lb];
        }
        return NULL;
    }
};

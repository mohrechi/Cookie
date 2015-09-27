#include <bits/stdc++.h>
using namespace std;
const int MAXS = 1e6 + 10;
const int MAXN = 200 + 10;

int n, m;
char s[MAXS];

struct Tag {
    char s[11];
    enum Type {
        OPEN,
        CLOSE,
        UNIFY
    } type;
    bool valid;
};
vector<Tag> tags;

void parseTag(char *s) {
    while (*s) {
        Tag tag;
        tag.type = Tag::OPEN;
        ++s;
        if (*s == '/') {
            tag.type = Tag::CLOSE;
            ++s;
        }
        int idx = 0;
        while ('a' <= *s && *s <= 'z') {
            tag.s[idx++] = *s;
            ++s;
        }
        tag.s[idx] = 0;
        if (*s == '/') {
            tag.type = Tag::UNIFY;
            ++s;
        }
        ++s;
        tags.push_back(tag);
    }
}

struct TreeNode {
    Tag *tag;
    vector<TreeNode*> child;
    TreeNode() {
        tag = nullptr;
    }
} head;

int buildTree(TreeNode *parent, int idx) {
    while (idx < (int)tags.size()) {
        if (tags[idx].type == Tag::UNIFY) {
            TreeNode *node = new TreeNode();
            node->tag = &tags[idx];
            parent->child.push_back(node);
            ++idx;
        } else if (tags[idx].type == Tag::OPEN) {
            TreeNode *node = new TreeNode();
            node->tag = &tags[idx];
            parent->child.push_back(node);
            idx = buildTree(node, idx + 1);
        } else {
            ++idx;
            break;
        }
    }
    return idx;
}

char sub[MAXN][11];

void dfs(TreeNode *node, int idx) {
    for (auto c : node->child) {
        if (strcmp(c->tag->s, sub[idx]) == 0) {
            if (idx == n - 1) {
                c->tag->valid = true;
                dfs(c, idx);
            } else {
                dfs(c, idx + 1);
            }
        } else {
            dfs(c, idx);
        }
    }
}

int main() {
    scanf("%s", s);
    parseTag(s);
    buildTree(&head, 0);
    scanf("%d\n", &m);
    while (m--) {
        gets(s);
        n = strlen(s);
        s[n] = ' ';
        s[n + 1] = 0;
        n = 0;
        for (int i = 0, j = 0; s[i]; ++i) {
            if (s[i] == ' ') {
                sub[n++][j] = 0;
                j = 0;
            } else {
                sub[n][j++] = s[i];
            }
        }
        for (auto& tag : tags) {
            tag.valid = false;
        }
        dfs(&head, 0);
        int ans = 0;
        for (auto& tag : tags) {
            ans += tag.valid;
        }
        printf("%d\n", ans);
    }
    return 0;
}

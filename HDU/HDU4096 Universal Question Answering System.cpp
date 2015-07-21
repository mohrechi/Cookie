#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;
const int MAXM = 2000 + 10;

struct Edge {
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;

int id;
map<string, int> nouns;
map<string, int> verbs;

void clear() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
    id = 0;
    nouns.clear();
    verbs.clear();
}

inline void addEdge(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

char s[MAXM];
char word[MAXN];
int space[MAXN];

void getWord(int idx) {
    int i;
    for (i = idx; ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'); ++i) {
        word[i - idx] = s[i];
    }
    word[i - idx] = 0;
}

inline int addNoun(int idx) {
    getWord(idx);
    map<string, int>::iterator it = nouns.find(word);
    if (it == nouns.end()) {
        nouns[word] = id;
        return id++;
    }
    return it->second;
}

inline int addVerb(int idx) {
    getWord(idx);
    map<string, int>::iterator it = verbs.find(word);
    if (it == verbs.end()) {
        verbs[word] = id;
        return id++;
    }
    return it->second;
}

char ans[MAXM];
int queryNum;
bool visit[MAXN];

void dfs(int u) {
    visit[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (!visit[v]) {
            dfs(v);
        }
    }
}

int main() {
    int T;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        clear();
        queryNum = 0;
        while (true) {
            gets(s);
            int len;
            int spaceNum = 0;
            for (len = 0; s[len]; ++len) {
                if (s[len] == ' ') {
                    space[++spaceNum] = len + 1;
                }
            }
            if (s[len - 1] == '.') {
                int u, v;
                if (spaceNum == 2) {
                    if (s[space[1]] == 'a') {
                        // noun_phrase are noun_phrase.
                        u = addNoun(0);
                        v = addNoun(space[2]);
                    } else {
                        // noun_phrase can verb_phrase.
                        u = addNoun(0);
                        v = addVerb(space[2]);
                    }
                } else {
                    if (s[space[4]] == 'c') {
                        // everything which can verb_phrase can verb_phrase.
                        u = addVerb(space[3]);
                        v = addVerb(space[5]);
                    } else {
                        // everything which can verb_phrase are noun_phrase.
                        u = addVerb(space[3]);
                        v = addNoun(space[5]);
                    }
                }
                addEdge(u, v);
            } else if (s[len - 1] == '?') {
                int u, v;
                if (spaceNum == 2) {
                    if (s[0] == 'a') {
                        // are noun_phrase noun_phrase?
                        u = addNoun(space[1]);
                        v = addNoun(space[2]);
                    } else {
                        // can noun_phrase verb_phrase?
                        u = addNoun(space[1]);
                        v = addVerb(space[2]);
                    }
                } else {
                    if (s[0] == 'c') {
                        // can everything which can verb_phrase verb_phrase?
                        u = addVerb(space[4]);
                        v = addVerb(space[5]);
                    } else {
                        // are everything which can verb_phrase noun_phrase?
                        u = addVerb(space[4]);
                        v = addNoun(space[5]);
                    }
                }
                memset(visit, false, sizeof(visit));
                dfs(u);
                ans[queryNum++] = visit[v] ? 'Y' : 'M';
            } else {
                break;
            }
        }
        ans[queryNum] = 0;
        printf("Case #%d:\n%s\n", t, ans);
    }
    return 0;
}

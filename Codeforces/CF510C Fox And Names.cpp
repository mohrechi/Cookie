#include <bits/stdc++.h>
using namespace std;

int degree[26];
bool graph[26][26];
char result[27];

int main() {
    int n;
    string prev, curr;
    while (cin >> n) {
        bool valid = true;
        memset(degree, 0, sizeof(degree));
        memset(graph, false, sizeof(graph));
        for (int i = 0; i < n; ++i) {
            cin >> curr;
            if (i) {
                if (curr.size() < prev.size()) {
                    if (prev.substr(0, curr.size()) == curr) {
                        valid = false;
                    }
                }
                for (int i = 0; i < (int)min(curr.size(), prev.size()); ++i) {
                    if (curr[i] != prev[i]) {
                        if (!graph[prev[i] - 'a'][curr[i] - 'a']) {
                            graph[prev[i] - 'a'][curr[i] - 'a'] = true;
                            ++degree[curr[i] - 'a'];
                        }
                        break;
                    }
                }
            }
            prev = curr;
        }
        for (int i = 0; i < 26 && valid; ++i) {
            for (int j = 0; j < 27; ++j) {
                if (j == 26) {
                    valid = false;
                    break;
                }
                if (degree[j] == 0) {
                    degree[j] = -1;
                    result[i] = j + 'a';
                    for (int k = 0; k < 26; ++k) {
                        if (graph[j][k]) {
                            --degree[k];
                        }
                    }
                    break;
                }
            }
        }
        if (valid) {
            cout << result << endl;
        } else {
            cout << "Impossible" << endl;
        }
    }
    return 0;
}

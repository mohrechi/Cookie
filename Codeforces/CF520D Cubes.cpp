#include <bits/stdc++.h>
using namespace std;
const int MAXM = 1e5 + 10;
const int MOD = 1e9 + 9;

struct Cube {
    int x, y;
    Cube() {}
    Cube(int _x, int _y) : x(_x), y(_y) {}
    bool operator <(const Cube& cube) const {
        if (y == cube.y) {
            return x < cube.x;
        }
        return y < cube.y;
    }
} cube[MAXM];

int m;
int supported[MAXM];
bool visit[MAXM];
map<Cube, int> cubeMap;
set<int> cubeSet;

set<int>::iterator getFirst(set<int>::iterator iter) {
    return cubeSet.begin();
}

set<int>::reverse_iterator getFirst(set<int>::reverse_iterator iter) {
    return cubeSet.rbegin();
}

template<class iter>
int findFirst(iter it) {
    while (true) {
        int index = *it;
        bool valid = true;
        for (int j = -1; j <= 1; ++j) {
            auto cubeIt = cubeMap.find(Cube(cube[index].x + j, cube[index].y + 1));
            if (cubeIt != cubeMap.end()) {
                if (supported[cubeIt->second] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            break;
        }
        cubeSet.erase(index);
        it = getFirst(it);
    }
    int index = *it;
    cubeSet.erase(index);
    supported[index] = 0;
    visit[index] = true;
    for (int j = -1; j <= 1; ++j) {
        auto cubeIt = cubeMap.find(Cube(cube[index].x + j, cube[index].y + 1));
        if (cubeIt != cubeMap.end()) {
            --supported[cubeIt->second];
        }
        cubeIt = cubeMap.find(Cube(cube[index].x + j, cube[index].y - 1));
        if (cubeIt != cubeMap.end()) {
            if (!visit[cubeIt->second]) {
                cubeSet.insert(cubeIt->second);
            }
        }
    }
    return index;
}

int main() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> cube[i].x >> cube[i].y;
        cubeMap[cube[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        cubeSet.insert(i);
        for (int j = -1; j <= 1; ++j) {
            if (cubeMap.find(Cube(cube[i].x + j, cube[i].y - 1)) != cubeMap.end()) {
                ++supported[i];
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = ans * m % MOD + findFirst(cubeSet.rbegin());
        ++i;
        if (i < m) {
            ans = ans * m % MOD + findFirst(cubeSet.begin());
        }
    }
    cout << ans % MOD << endl;
    return 0;
}

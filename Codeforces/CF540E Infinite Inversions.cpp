#include <bits/stdc++.h>
using namespace std;

class BIT {
public:
    BIT(int num) :
        n(num), bits(num + 1, 0) {
    }

    void update(int x) {
        ++x;
        while (x <= n) {
            ++bits[x];
            x += lowbit(x);
        }
    }

    int query(int x) {
        ++x;
        int sum = 0;
        while (x) {
            sum += bits[x];
            x -= lowbit(x);
        }
        return sum;
    }

    int query(int x, int y) {
        return query(y) - query(x - 1);
    }

private:
    int n;
    vector<int> bits;

    inline int lowbit(int x) {
        return x & (-x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> b(n);
        set<int> nums;
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            nums.insert(a[i]);
            nums.insert(b[i]);
        }
        int index = 0;
        map<int, int> indexes;
        map<int, int> origin;
        vector<int> seq(nums.size());
        for (auto num : nums) {
            seq[index] = num;
            origin[index] = num;
            indexes[num] = index++;
        }
        for (int i = 0; i < n; ++i) {
            swap(seq[indexes[a[i]]], seq[indexes[b[i]]]);
        }
        map<int, int> finalPos;
        for (int i = 0; i < index; ++i) {
            finalPos[seq[i]] = i;
        }
        BIT order(index);
        long long ans = 0;
        for (auto num : nums) {
            int fpos = finalPos[num];
            int ipos = indexes[num];
            int opos = origin[fpos];
            ans += abs(num - opos) - abs(ipos - fpos);
            ans += order.query(fpos, index - 1);
            order.update(fpos);
        }
        cout << ans << endl;
    }
    return 0;
}

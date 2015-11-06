class MedianFinder {
public:
    void addNum(int num) {
        if (large.size() == 0 || num < *large.begin()) {
            small.insert(num);
            if (small.size() > large.size() + 1) {
                large.insert(*small.begin());
                small.erase(small.begin());
            }
        } else {
            large.insert(num);
            if (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return *small.begin();
        }
        return (*small.begin()) * 0.5 + (*large.begin()) * 0.5;
    }
private:
    multiset<int, greater<int>> small;
    multiset<int> large;
};

#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

class GoodCounterSingle
{
public:
    inline void clear()
    {
        num.clear();
        count = 0;
    }
    inline void addInitValue(const int &x)
    {
        add(x);
    }
    inline void add(const int &x)
    {
        count += num[x];
        ++num[x];
    }
    inline void sub(const int &x)
    {
        --num[x];
        count -= num[x];
    }
    inline long long getGoodNum() const
    {
        return count;
    }
private:
    map<int, int> num;
    long long count;
};

class GoodCounterDouble
{
public:
    inline void clear()
    {
        leftNum.clear();
        rightNum.clear();
        count = 0;
    }
    inline void addInitValue(const int &x)
    {
        ++rightNum[x];
    }
    inline void addLeft(const int &x)
    {
        count += rightNum[x];
        ++leftNum[x];
    }
    inline void addRight(const int &x)
    {
        count += leftNum[x];
        ++rightNum[x];
    }
    inline void subLeft(const int &x)
    {
        count -= rightNum[x];
        --leftNum[x];
    }
    inline void subRight(const int &x)
    {
        count -= leftNum[x];
        --rightNum[x];
    }
    inline long long getGoodNum() const
    {
        return count;
    }
private:
    map<int, int> leftNum;
    map<int, int> rightNum;
    long long count;
};

class Num1Counter
{
public:
    void init(int array[MAXN], int sum)
    {
        counter.clear();
        counter.addInitValue(array[0]);
        counter.addInitValue(array[1]);
    }
    inline void add(const int &x)
    {
        counter.add(x);
    }
    inline void sub(const int &x)
    {
        counter.sub(x);
    }
    inline long long count() const
    {
        return counter.getGoodNum();
    }
private:
    GoodCounterSingle counter;
};

class Num2Counter
{
public:
    void init(int array[MAXN], int n)
    {
        left.clear();
        right.clear();
        bridge.clear();
        left.addInitValue(array[0]);
        right.addInitValue(array[1]);
        for (int i = 2; i <= n; ++i)
        {
            right.addInitValue(array[i]);
            bridge.addInitValue(array[i]);
        }
    }
    inline void addLeft(const int &x)
    {
        left.add(x);
    }
    inline void addRight(const int &x)
    {
        right.add(x);
    }
    inline void addBridgeLeft(const int &x)
    {
        bridge.addLeft(x);
    }
    inline void addBridgeRight(const int &x)
    {
        bridge.addRight(x);
    }
    inline void subRight(const int &x)
    {
        right.sub(x);
    }
    inline void subBridgeRight(const int &x)
    {
        bridge.subRight(x);
    }
    inline void subBridgeLeft(const int &x)
    {
        bridge.subLeft(x);
    }
    inline long long count() const
    {
        return left.getGoodNum() + right.getGoodNum() + bridge.getGoodNum();
    }
private:
    GoodCounterSingle left;
    GoodCounterSingle right;
    GoodCounterDouble bridge;
};

class NumCounter
{
public:
    void init(int array[MAXN], int n)
    {
        this->array = array;
        this->n = n;
        counter1.init(array, n);
        counter2.init(array, n);
    }
    inline void moveLeft()
    {
        counter1.sub(array[left - 1]);
        counter2.addLeft(array[left]);
        counter2.addBridgeLeft(array[left - 1]);
        while (right > last[left] && right > left + 1)
        {
            counter2.addBridgeRight(array[right]);
            counter2.addRight(array[right - 1]);
            counter1.sub(array[right]);
            --right;
        }
        ++left;
    }
    inline void moveRight()
    {
        ++right;
        counter1.add(array[right]);
        counter2.subRight(array[right - 1]);
        counter2.subBridgeRight(array[right]);
    }
    int getEqualNum()
    {
        int res = 0;
        left = 1, right = 1;
        memset(last, 0x3f, sizeof(last));
        while (left <= n)
        {
            if (counter1.count() <= counter2.count())
            {
                if (counter1.count() == counter2.count())
                {
                    last[left] = min(last[left], right);
                    ++res;
                }
                if (right >= n)
                {
                    moveLeft();
                }
                else
                {
                    moveRight();
                }
            }
            else
            {
                moveLeft();
            }
        }
        return res;
    }
private:
    Num1Counter counter1;
    Num2Counter counter2;
    int left, right;
    int *array, n;
    int last[MAXN];
} counter;

int n;
char str[MAXN];
int sum[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        scanf("%s", str + 1);
        for (int i = 1; i <= n; ++i)
        {
            if (str[i] == '1')
            {
                sum[i] = sum[i - 1] + 2;
            }
            else
            {
                sum[i] = sum[i - 1] - 1;
            }
        }
        counter.init(sum, n);
        printf("%d\n", counter.getEqualNum());
    }
    return 0;
}

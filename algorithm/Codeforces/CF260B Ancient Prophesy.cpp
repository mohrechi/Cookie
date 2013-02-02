#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 100100;
const bool digitPos[] = {1, 1, 0, 1, 1, 0, 1, 1, 1, 1};
const int digitPosNum = 10;
const int days[] = {0, 31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

char s[MAXN];

inline bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

inline int getNum(const char *str, int n)
{
    int res = 0;
    for(int i=0;i<n;++i)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

inline void printZero(int x)
{
    if(x < 10)
    {
        printf("0");
    }
    printf("%d", x);
}

struct Date
{
    int year, month, day;
    int time;

    bool tryParse(const char *date)
    {
        for(int i=0;i<digitPosNum;++i)
        {
            if(digitPos[i])
            {
                if(!isDigit(date[i]))
                {
                    return false;
                }
            }
            else
            {
                if(date[i] != '-')
                {
                    return false;
                }
            }
        }
        day = getNum(date, 2);
        month = getNum(date + 3, 2);
        year = getNum(date + 6, 4);
        if(year < 2013 || year > 2015)
        {
            return false;
        }
        if(month < 1 || month > 12)
        {
            return false;
        }
        if(day < 1 || day > days[month])
        {
            return false;
        }
        time = year * 10000 + month * 100 + day;
        return true;
    }

    bool operator < (const Date &date) const
    {
        return time < date.time;
    }

    void output()
    {
        printZero(day);
        printf("-");
        printZero(month);
        printf("-%d\n", year);
    }
} ;

map<Date, int> dateNum;

int main()
{
    while(~scanf("%s", s))
    {
        Date date;
        dateNum.clear();
        for(int i=0;s[i];++i)
        {
            if(date.tryParse(s + i))
            {
                ++ dateNum[date];
            }
        }
        int ans = 0;
        for(map<Date, int>::iterator it=dateNum.begin();it!=dateNum.end();++it)
        {
            if(it->second > ans)
            {
                ans = it->second;
                date = it->first;
            }
        }
        date.output();
    }
    return 0;
}

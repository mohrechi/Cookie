#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int NMOR = 10;
const int NEVE = 20;

struct Date
{
    int year, month, day;
    int hour, minute, second;
    int date, time;
    inline void input()
    {
        scanf("%d%d%d", &hour, &minute, &second);
        scanf("%d%d%d", &year, &month, &day);
        convert();
    }
    inline void output()
    {
        printf("%d %d %d %d %d %d\n", year, month, day, hour, minute, second);
    }
    inline void convert()
    {
        date = year * 13 * 31 + (month - 1) * 31 + day - 1;
        time = hour * 60 * 60 + minute * 60 + second;
    }
    bool operator <(const Date &d) const
    {
        if (date == d.date)
        {
            return time < d.time;
        }
        return date < d.date;
    }
} date[MAXN], dmor1, dmor2, deve1, deve2;

int main()
{
    int T, n;
    dmor1.hour = 7;
    dmor1.minute = 0;
    dmor1.second = 0;
    dmor1.convert();

    dmor2.hour = 8;
    dmor2.minute = 30;
    dmor2.second = 0;
    dmor2.convert();

    deve1.hour = 16;
    deve1.minute = 0;
    deve1.second = 0;
    deve1.convert();

    deve2.hour = 21;
    deve2.minute = 30;
    deve2.second = 0;
    deve2.convert();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            date[i].input();
        }
        int morCount = 0;
        int eveCount = 0;
        bool morFlag;
        bool eveFlag1;
        bool eveFlag2;
        Date firstEve;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || (i && (date[i].year != date[i - 1].year || date[i].month != date[i - 1].month || date[i].day != date[i - 1].day)))
            {
                morFlag = false;
                eveFlag1 = false;
                eveFlag2 = false;
            }
            if (date[i].time >= dmor1.time && date[i].time <= dmor2.time)
            {
                if (!morFlag)
                {
                    morFlag = true;
                    ++morCount;
                }
            }
            if (date[i].time >= deve1.time && date[i].time <= deve2.time)
            {
                if (!eveFlag1)
                {
                    eveFlag1 = true;
                    firstEve = date[i];
                }
                else
                {
                    if (!eveFlag2)
                    {
                        if (date[i].time - firstEve.time >= 1800)
                        {
                            eveFlag2 = true;
                            ++eveCount;
                        }
                    }
                }
            }
        }
        if (morCount > NMOR)
        {
            morCount = NMOR;
        }
        if (eveCount > NEVE)
        {
            eveCount = NEVE;
        }
        printf("%d %d\n", NMOR - morCount, NEVE - eveCount);
    }
    return 0;
}

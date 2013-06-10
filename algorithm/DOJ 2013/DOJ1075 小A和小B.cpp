#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int days[] = {0,
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

struct DateTime
{
    struct Date
    {
        int year, month, day;
        inline int input()
        {
            return ~scanf("%d/%d/%d", &year, &month, &day);
        }
        int countNextYear()
        {
            return 365 + isLeapYear(year + 1);
        }
        bool isYearEnd()
        {
            return month == 12 && day == 31;
        }
        bool isLeapYear(int x)
        {
            if (x % 100 == 0)
            {
                return x % 400 == 0;
            }
            return x % 4 == 0;
        }
        inline void addDay()
        {
            day = day + 1;
            if (month == 2)
            {
                if (isLeapYear(year))
                {
                    if (day > 29)
                    {
                        day = 1;
                        month = 3;
                    }
                }
                else
                {
                    if (day > 28)
                    {
                        day = 1;
                        month = 3;
                    }
                }
            }
            else
            {
                if (day > days[month])
                {
                    day = 1;
                    month = month + 1;
                    if (month > 12)
                    {
                        ++year;
                        month = 1;
                    }
                }
            }
        }
        inline void addYear()
        {
            ++year;
        }
        inline void output()
        {
            printf("%d/", year);
            if (month < 10)
            {
                printf("0");
            }
            printf("%d/", month);
            if (day < 10)
            {
                printf("0");
            }
            printf("%d", day);
        }
    } date;
    struct Time
    {
        int hour, minute, second;
        int trans;
        inline void input()
        {
            scanf("%d:%d:%d", &hour, &minute, &second);
            trans = hour * 60 * 60 + minute * 60 + second;
        }
        void translate()
        {
            hour = trans / 3600;
            minute = (trans % 3600) / 60;
            second = trans % 60;
        }
        inline void output()
        {
            if (hour < 10)
            {
                printf("0");
            }
            printf("%d:", hour);
            if (minute < 10)
            {
                printf("0");
            }
            printf("%d:", minute);
            if (second < 10)
            {
                printf("0");
            }
            printf("%d", second);
        }
    } time;
    inline int input()
    {
        int temp = date.input();
        if (temp)
        {
            time.input();
        }
        return temp;
    }
    inline void output()
    {
        date.output();
        putchar(' ');
        time.output();
        putchar('\n');
    }
};

int main()
{
    long long past;
    DateTime dateTime;
    while (dateTime.input())
    {
        cin >> past;
        int dateTrans = (past + dateTime.time.trans) / 86400;
        int timeTrans = (past + dateTime.time.trans) % 86400;
        while (!dateTime.date.isYearEnd() && dateTrans > 0)
        {
            dateTime.date.addDay();
            --dateTrans;
        }
        while (dateTrans >= dateTime.date.countNextYear())
        {
            dateTrans -= dateTime.date.countNextYear();
            dateTime.date.addYear();
        }
        while (dateTrans > 0)
        {
            dateTime.date.addDay();
            --dateTrans;
        }
        dateTime.time.trans = timeTrans;
        dateTime.time.translate();
        dateTime.output();
    }
    return 0;
}

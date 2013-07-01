#include <cstdio>
#include <cstring>

static const int dayNumber[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
public:
    int year, month, day;
    int hour, minute, second;
    long long past;
    long long total;

    bool isLeapYear(int y)
    {
        if(y % 100 == 0)
        {
            return y % 400 == 0;
        }
        return y % 4 == 0;
    }

    void input()
    {
        scanf("%d/%d/%d %d:%d:%d %lld",&year,&month,&day,&hour,&minute,&second,&past);
    }

    void getTotal()
    {
        total = 0;
        for(int i=2000;i<year;++i)
        {
            if(isLeapYear(i))
            {
                total += 31622400;
            }
            else
            {
                total += 31536000;
            }
        }
        for(int i=1;i<month;++i)
        {
            total += dayNumber[i] * 86400;
            if(i == 2)
            {
                if(isLeapYear(year))
                {
                    total += 86400;
                }
            }
        }
        total += day * 86400;
        total += hour * 3600;
        total += minute * 60;
        total += second;
        total += past;
    }

    void process()
    {
        second = total % 60;
        total /= 60;
        minute = total % 60;
        total /= 60;
        hour = total % 24;
        total /= 24;
        year = 2000;
        while(true)
        {
            if(isLeapYear(year))
            {
                if(total > 366)
                {
                    total -= 366;
                    ++ year;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(total > 365)
                {
                    total -= 365;
                    ++ year;
                }
                else
                {
                    break;
                }
            }
        }
        for(month=1;total>0;++month)
        {
            if(month == 2 && isLeapYear(year))
            {
                if(total > dayNumber[month] + 1)
                {
                    total -= dayNumber[month] + 1;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(total > dayNumber[month])
                {
                    total -= dayNumber[month];
                }
                else
                {
                    break;
                }
            }
        }
        day = total;
    }

    void output()
    {
        printf("%d/", year);
        if(month < 10) printf("0");
        printf("%d/", month);
        if(day < 10) printf("0");
        printf("%d ", day);
        if(hour < 10) printf("0");
        printf("%d:", hour);
        if(minute < 10) printf("0");
        printf("%d:", minute);
        if(second < 10) printf("0");
        printf("%d\n", second);
    }
};

int main()
{
    Date *date = new Date();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        date->input();
        date->getTotal();
        date->process();
        date->output();
    }
    return 0;
}

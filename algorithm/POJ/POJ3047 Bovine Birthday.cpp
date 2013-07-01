#include <cstdio>

char week[][10] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main(int argc, char *argv[])
{
    int day, month, year, ans;
    scanf("%d%d%d",&year,&month,&day);
    if(month == 1 || month == 2)
    {
        month += 12;
        -- year;
    }
    if((year < 1752) || (year == 1752 && month < 9) || (year == 1752 && month==9 && day<3))
        ans = (day + 2 * month + 3 * (month + 1) / 5 + year + year/4 + 5) % 7;
    else
        ans = (day + 2 * month + 3 * (month + 1) / 5 + year + year/4 - year/100 + year/400) % 7;
    printf("%s\n",week[ans]);
    return 0;
}

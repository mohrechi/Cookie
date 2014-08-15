#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
const int MAXN = 43;

string str[MAXN] = {
    "HDU1524",
    "HDU3094",
    "POJ2599",
    "HDU1525 / POJ2348",
    "HDU1564",
    "HDU1847",
    "HDU2516",
    "HDU2897",
    "HDU3537",
    "HDU3863",
    "HDU3951",
    "POJ2484",
    "HDU1538",
    "HDU1729",
    "HDU1760",
    "HDU1848",
    "HDU1849",
    "HDU1851",
    "HDU1907 / POJ3480 / ZOJ3113",
    "HDU2509",
    "HDU2873",
    "HDU2999",
    "HDU4111",
    "HDU4155 / ZOJ1827",
    "HDU4203",
    "HDU4387",
    "POJ1740",
    "POJ2234",
    "POJ2975 / ZOJ3067",
    "POJ2425",
    "POJ1678",
    "POJ2068",
    "POJ3537",
    "POJ2931",
    "ZOJ2290",
    "ZOJ2686",
    "ZOJ2083",
    "ZOJ3513",
    "ZOJ3529",
    "ZOJ3591",
    "ZOJ3057",
    "ZOJ1039",
    "ZOJ2804"
};

int main()
{
    sort(str, str + MAXN);
    for (int i = 0; i < MAXN; ++i)
    {
        cout << str[i] << endl;
    }
    return 0;
}

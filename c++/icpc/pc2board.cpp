/**
 * 对PC^2生成的board进行简单的处理，生成HDU的board样式。
 * 注：现在是2013年4月。
 * @author ZHG <CyberZHG@gmail.com>
 */
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int PROBLEM_NUMBER = 11;

int parseInt(const string str, const int start, const int end)
{
    int res = 0;
    for (int i = start; i < end; ++i)
    {
        if (str[i] == '-')
        {
            return -1;
        }
        res = res * 10 + str[i] - '0';
    }
    return res;
}

int findSep(const string str)
{
    for (int i = 0; i <str.length(); ++i)
    {
        if (str[i] == '/')
        {
            return i;
        }
    }
    return -1;
}

void printTime(int time)
{
    if (time / 60 < 10)
    {
        cout << "0";
    }
    cout << time / 60;
    cout << ":";
    if (time % 60 < 10)
    {
        cout << "0";
    }
    cout << time % 60;
}

void printTime(int submit, int time)
{
    if (submit > 0)
    {
        if (time >= 0)
        {
            printTime(time);
        }
        if (submit > 1)
        {
            if (time >= 0)
            {
                cout << "<br/>" << "(-" << submit - 1 << ")";
            }
            else
            {
                cout << "(-" << submit << ")";
            }
        }
        else
        {
            if (time < 0)
            {
                cout << "(-" << submit << ")";
            }
        }
    }
}

void printTd(bool odd)
{
    if (odd)
    {
        cout << "<td>";
    }
    else
    {
        cout << "<td style = 'background-color: rgb(215,235,235);'>";
    }
}

vector<string> teamName;
vector<vector<int> > submitCount;
vector<vector<int> > acceptedTime;
vector<int> solved;
vector<int> penalty;
vector<int> firstBloodTime;

int main()
{
    freopen("data.txt", "r", stdin);
    freopen("Final Borad.html", "w", stdout);
    string temp;
    for (int i = 0; i < PROBLEM_NUMBER; ++i)
    {
        firstBloodTime.push_back(-1);
    }
    while (cin >> temp)
    {
        teamName.push_back(temp);
        submitCount.push_back(vector<int>());
        acceptedTime.push_back(vector<int>());
        solved.push_back(0);
        penalty.push_back(0);
        for (int i = 0; i < PROBLEM_NUMBER; ++i)
        {
            cin >> temp;
            int sep = findSep(temp);
            submitCount[submitCount.size() - 1].push_back(parseInt(temp, 0, sep));
            acceptedTime[acceptedTime.size() - 1].push_back(parseInt(temp, sep + 1, temp.length()));
            if (acceptedTime[acceptedTime.size() - 1][i] != -1)
            {
                ++solved[solved.size() - 1];
                penalty[penalty.size() - 1] += acceptedTime[acceptedTime.size() - 1][i] + (submitCount[submitCount.size() - 1][i] - 1) * 20;
                if (firstBloodTime[i] == -1)
                {
                    firstBloodTime[i] = acceptedTime[acceptedTime.size() - 1][i];
                }
                else
                {
                    firstBloodTime[i] = min(firstBloodTime[i], acceptedTime[acceptedTime.size() - 1][i]);
                }
            }
        }
        cin >> temp;
    }
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html>" << endl;
    cout << "<head>" << endl;
    cout << "<meta charset = UTF-8>" << endl;
    cout << "<title>Final Board</title>" << endl;
    cout << "</head>" << endl;
    cout << "<body>" << endl;
    cout << "<table width = 100% style = 'font-size: 14px; text-align: center'>" << endl;
    cout << "<tr>" << endl;
    cout << "<th style = 'background-color: blue; color: white'>Rank</th>" << endl;
    cout << "<th style = 'background-color: blue; color: white'>Name</th>" << endl;
    cout << "<th style = 'background-color: blue; color: white'>Solved</th>" << endl;
    cout << "<th style = 'background-color: blue; color: white'>Penalty</th>" << endl;
    for (int i = 0; i < PROBLEM_NUMBER; ++i)
    {
        cout << "<th style = 'background-color: blue; color: white'>" << (char)('A' + i) << "</th>" << endl;
    }
    cout << "</tr>" << endl;
    int rank = 0;
    bool odd = true;
    for (int i = 0; i < teamName.size(); ++i)
    {
        if (penalty[i] <= 0)
        {
            //continue;
        }
        cout << "<tr>" << endl;
        printTd(odd);
        cout << ++rank << "</td>" << endl;
        printTd(odd);
        cout << teamName[i] << "</td>" << endl;
        printTd(odd);
        cout << solved[i] << "</td>" << endl;
        printTd(odd);
        printTime(penalty[i]);
        cout << "</td>" << endl;
        for (int j = 0; j < PROBLEM_NUMBER; ++j)
        {
            cout << "<td ";
            if (acceptedTime[i][j] >= 0)
            {
                if (acceptedTime[i][j] == firstBloodTime[j])
                {
                    cout << "style = 'background-color:rgb(67, 205, 128); color: white'>";
                }
                else
                {
                    cout << "style = 'background-color: green; color: white'>";
                }
            }
            else if (submitCount[i][j] > 0)
            {
                cout << "style = 'background-color: red; color: white'>";
            }
            else
            {
                if (!odd)
                {
                    cout << "style = 'background-color: rgb(215,235,235);'";
                }
                cout << ">";
            }
            printTime(submitCount[i][j], acceptedTime[i][j]);
            cout << "</td>" << endl;
        }
        cout << "</tr>" << endl;
        odd = !odd;
    }
    cout << "</table>" << endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
    return 0;
}

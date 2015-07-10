#include <bits/stdc++.h>
using namespace std;

int main() {
    int num = 0;
    set<string> people;
    string command;
    while (getline(cin, command)) {
        if (command[0] == '+') {
            people.insert(command.substr(1));
        } else if (command[0] == '-') {
            people.erase(command.substr(1));
        } else {
            for (int i = 0; i < (int)command.size(); ++i) {
                if (command[i] == ':') {
                    num += ((int)command.size() - i - 1) * people.size();
                }
            }
        }
    }
    cout << num << endl;
    return 0;
}

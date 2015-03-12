#include <bits/stdc++.h>
using namespace std;

string subUntil(string& input, int& index, char end) {
    int start = index;
    for (; input[index] != end; ++index);
    return input.substr(start, index - start);
}

int main() {
    bool comma = false;
    string object, subject, verb, conjunction;
    string input, output;
    getline(cin, input);
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == ',') {
            comma = true;
            output += object + " " + subject + " " + verb + ", ";
        } else if (input[i] == ' ') {
            continue;
        } else if (input[i] == '{') {
            ++i;
            object = subUntil(input, i, '}');
            if (comma) {
                object[0] = tolower(object[0]);
            } else {
                object[0] = toupper(object[0]);
            }
        } else if (input[i] == '(') {
            ++i;
            subject = subUntil(input, i, ')');
            subject[0] = tolower(subject[0]);
        } else if (input[i] == '[') {
            ++i;
            verb = subUntil(input, i, ']');
            verb[0] = tolower(verb[0]);
        } else {
            conjunction = subUntil(input, i, ' ');
            output += conjunction + " ";
        }
    }
    output += object + " " + subject + " " + verb;
    cout << output;
    return 0;
}

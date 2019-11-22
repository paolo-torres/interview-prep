#include <stdio.h>

#include <cctype>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    string s = "Five years ago, we lost. All of us. We lost friends. "
               "We lost family. We lost a part of ourselves. "
               "Today, we have a chance to take it all back. "
               "You know your teams, you know your missions. "
               "Get the stones, get them back. One round trip each. "
               "No mistakes. No do-overs. "
               "Most of us are going somewhere we know, "
               "that doesn't mean we should know what to expect. "
               "Be careful. Look out for each other. "
               "This is the fight of our lives. And we're going to win. "
               "Whatever it takes. Good luck.";
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (isalpha(*it)) {
            *it = tolower(*it);
        } else {
            *it = ' ';
        }
    }
    string temp;
    stringstream ss(s);
    map<string, int> m;
    while (ss >> temp) {
        auto it = m.find(temp);
        if (it != m.end()) {
            it->second++;
        } else {
            m.insert({temp, 1});
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "Word: " << it->second << " Count: " << it->first << endl;
    }

    return 0;
}

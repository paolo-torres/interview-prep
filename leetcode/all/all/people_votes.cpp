#include <stdio.h>

#include <iostream>
#include <map>

using namespace std;

int main()
{
    string votes[] = {"john", "johnny", "jackie", 
                      "johnny", "john", "jackie", 
                      "jamie", "jamie", "john",
                      "johnny", "jamie", "johnny", 
                      "john"};
    int length = sizeof(votes) / sizeof(votes[0]);
    map<string, int> m;
    for (int i = 0; i < length; i++) {
        auto it = m.find(votes[i]);
        if (it != m.end()) {
            it->second++;
        } else {
            m.insert({votes[i], 1});
        }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << "Name: " << it->first << " | Votes: " << it->second << endl;
    }

    return 0;
}

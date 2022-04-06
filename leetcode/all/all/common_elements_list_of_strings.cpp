#include <stdio.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> commonElements(vector<string>& s1, vector<string>& s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<string> bigger;
    vector<string> smaller;
    if (s1.size() >= s2.size()) {
        bigger = s1;
        smaller = s2;
    } else {
        bigger = s2;
        smaller = s1;
    }
    vector<string> result;
    int i = 0;
    int j = 0;
    while (i < bigger.size() && j < smaller.size()) {
        if (s1[i] == s2[j]) {
            result.push_back(s1[i]);
            i++;
            j++;
        } else if (s1[i] > s2[j]) {
            j++;
        } else {
            i++;
        }
    }
    return result;
}

int main()
{
    vector<string> s1 = {"alpha","beta","charlie","delta"};
    vector<string> s2 = {"epsilon","alpha","charlie"};
    vector<string> result = commonElements(s1, s2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}

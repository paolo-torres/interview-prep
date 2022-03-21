#include <stdio.h>

#include <iostream>

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool isValid(string copy) {
    sort(copy.begin(), copy.end());
    for (int i = 0, j = i + 1; j < copy.size(); i++, j++) {
        if (copy[i] == copy[j]) {
            return false;
        }
    }
    return true;
}

vector<string> substringKSizeKDistinctChars(string s, int k) {
    auto start = s.begin();
    int index = 0;
    auto end = start + k - 1;
    set<string> mySet;
    while (end < s.end()) {
        string str = s.substr(index, k);
        if (isValid(str)) {
            if (mySet.find(str) == mySet.end()) {
                mySet.insert(str);
            }
        }
        start++;
        index++;
        end++;
    }
    vector<string> result;
    for(auto it = mySet.begin(); it != mySet.end(); ++it) {
        result.push_back(*it);
    }
    return result;
}

void output(vector<string> &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    string s[3] = {"abcabc", "abacab", "awaglknagawunagwkwagl"};
    int k[3] = {3, 3, 4};
    for (int i = 0; i < 3; i++) {
        vector<string> v = substringKSizeKDistinctChars(s[i], k[i]);
        output(v);
    }

    return 0;
}

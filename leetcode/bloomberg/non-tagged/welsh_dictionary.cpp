/*
    Given a Welsh dictionary, sorted in Welsh alphabetical order, and
    a list of words written in the Welsh language, sort the list of
    words in Welsh alphabetical order.
    
    Hash map {"letter" -> index}, loop thru input, sort based on this

    Time: O(n log n)
    Space: O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> welsh(vector<string>& alphabet, vector<string>& input) {
        for (int i = 0; i < alphabet.size(); i++) {
            m[alphabet[i]] = i;
        }

        vector<vector<int>> curr(input.size());
        for (int i = 0; i < input.size(); i++) {
            int n = input[i].size();
            int j = 0;
            while (j < n) {
                if (j < n - 1) {
                    string s = input[i].substr(j, 2);
                    if (m.find(s) != m.end()) {
                        curr[i].push_back(m[s]);
                        j += 2;
                    } else {
                        string s = input[i].substr(j, 1);
                        curr[i].push_back(m[s]);
                        j++;
                    }
                } else {
                    string s = input[i].substr(j, 1);
                    curr[i].push_back(m[s]);
                    j++;
                }
            }
        }
        sort(curr.begin(), curr.end());

        vector<string> result(input.size());
        for (int i = 0; i < curr.size(); i++) {
            for (int j = 0; j < curr[i].size(); j++) {
                result[i] += alphabet[curr[i][j]];
            }
        }
        return result;
    }
private:
    // {"letter" -> index}
    unordered_map<string, int> m;
};

int main() {
    vector<string> alphabet = {
        "a", "b", "c", "ch", "d", "dd", "e", "f", "ff", "g", "ng",
        "h", "i", "l", "ll", "m", "n", "o", "p", "ph", "r", "rh", "s",
        "t", "th", "u", "w", "y"
    };
    vector<string> input = {"ddr", "nah", "dea", "dd", "ngah"};
    Solution* obj = new Solution();

    vector<string> result = obj->welsh(alphabet, input);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}

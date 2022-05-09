/*
    Given a string & an int k, make k duplicate removals until we no longer can
    Return final string after all such duplicate removals have been made
    s = "deeedbbcccbdaa", k = 3 -> "aa", delete: "eee", "ccc", "bbb", "ddd"

    Maintain char counts, if count = k remove, use stack to perform removals

    Time: O(n)
    Space: O(n)
*/

// Time: O(n^2 / k), Space: O(1)
// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         int length = -1;
//         while (length != s.size()) {
//             length = s.size();
//             for (int i = 0, count = 1; i < s.size(); i++) {
//                 if (i == 0 || s[i] != s[i - 1]) {
//                     count = 1;
//                 } else if (++count == k) {
//                     s.erase(i - k + 1, k);
//                     break;
//                 }
//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string removeDuplicates(string s, int k) {
        // pair of {char -> frequency}
        vector<pair<char, int>> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (stk.empty() || stk.back().first != s[i]) {
                stk.push_back({s[i], 1});
                continue;
            }
            
            // increase frequency
            stk.back().second++;
            // if reach k duplicate chars, then remove
            if (stk.back().second == k) {
                stk.pop_back();
            }
        }
        
        string result;
        for (int i = 0; i < stk.size(); i++) {
            result.append(stk[i].second, stk[i].first);
        }
        return result;
    }
};

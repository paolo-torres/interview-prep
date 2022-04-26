/*
    Given 2 strings, return true if 1 string can be constructed from the other
    Ex. ransom = "a" magazine = "b" -> false, ransom = "aa", magazine = "aab" -> true

    Simulate -> optimize w/ char freq hash map, count up magazine, count down ransom

    Time: O(n) -> optimized from O(m x n)
    Space: O(1)
*/

// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         for (int i = 0; i < ransomNote.size(); i++) {
//             auto index = magazine.find(ransomNote[i]);
//             if (index == string::npos) {
//                 return false;
//             }
//             magazine = magazine.substr(0, index) + magazine.substr(index + 1);
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26);
        for (int i = 0; i < magazine.size(); i++) {
            count[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            count[ransomNote[i] - 'a']--;
            if (count[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

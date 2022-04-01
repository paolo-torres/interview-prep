// Char count hash map, optimize to single pass
// If s size even, every char must occur even times
// If odd, every char must occur even times except 1

// // Time: O(n)
// // Space: O(1)

// class Solution {
// public:
//     bool canPermutePalindrome(string s) {
//         vector<int> count(26);
//         for (int i = 0; i < s.size(); i++) {
//             count[s[i] - 'a']++;
//         }
        
//         int oddOccurrences = 0;
//         for (int i = 0; i < 26; i++) {
//             if (oddOccurrences > 1) {
//                 return break;
//             }
//             oddOccurrences += count[i] % 2;
//         }
//         return oddOccurrences <= 1;
//     }
// };

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count(26);
        int oddOccurrences = 0;
        
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            if (count[s[i] - 'a'] % 2 == 0) {
                oddOccurrences--;
            } else {
                oddOccurrences++;
            }
        }
        
        return oddOccurrences <= 1;
    }
};

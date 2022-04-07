// https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/129021/O(N)-Java-Solution-DP-Clear-and-easy-to-Understand

// Time: O(n)
// Space: O(26)

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> contribution(26);
        vector<int> lastPosition(26);
        
        int result = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i] - 'A';
            
            int substringsEndingHere = i + 1;
            contribution[c] = substringsEndingHere - lastPosition[c];
            
            int curr = 0;
            for (int j = 0; j < 26; j++) {
                curr += contribution[j];
            }
            
            lastPosition[c] = i + 1;
            result += curr;
        }
        
        return result;
    }
};

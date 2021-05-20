// Time: O(n)
// Space: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> letters;

        int i = 0;
        int j = 0;
        int result = 0;
        
        while (j < s.size()) {
            if (letters.find(s[j]) == letters.end()) {
                letters.insert(s[j]);
                j++;
                result = max(result, j - i);
            } else {
                letters.erase(s[i]);
                i++;
            }
        }

        return result;
    }
};

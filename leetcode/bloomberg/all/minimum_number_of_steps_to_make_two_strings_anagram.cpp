// Count freq of each char, add up diffs

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26);
        for (int i = 0; i < s.size(); i++) {
            // count occurrences in s
            count[s[i] - 'a']++;
            // get diff between s & t
            count[t[i] - 'a']--;
        }
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += max(0, count[i]);
        }
        return result;
    }
};

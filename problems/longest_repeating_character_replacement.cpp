// Time: O(n)
// Space: O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        
        int i = 0;
        int maxCount = 0;
        int result = 0;
        
        for (int j = 0; j < s.size(); j++) {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            
            if (j - i + 1 - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }
            
            result = max(result, j - i + 1);
        }
        
        return result;
    }
};

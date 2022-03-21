// Time: O(n)
// Space: O(26)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        
        vector<int> orig(26);
        for (int i = 0; i < m; i++) {
            orig[s1[i] - 'a']++;
        }
        vector<int> count = orig;
        
        for (int i = 0; i <= n - m; i++) {
            if (count[s2[i] - 'a'] > 0) {
                for (int j = i; j < n; j++) {
                    count[s2[j] - 'a']--;
                    if (count[s2[j] - 'a'] < 0) {
                        break;
                    }
                    if (j - i + 1 == m) {
                        return true;
                    }
                }
                count = orig;
            }
        }
        
        return false;
    }
};

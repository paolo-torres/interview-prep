// Store char counts, find 1st w/ count = 1

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> count(26);
        
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};

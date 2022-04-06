// Count chars in s, write all chars in order, write remaining

// Time: O(m + n)
// Space: O(n)

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }
        
        string result = "";
        
        for (int i = 0; i < order.size(); i++) {
            result.append(count[order[i] - 'a'], order[i]);
            count[order[i] - 'a'] = 0;
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                result.append(count[i], i + 'a');
            }
        }
        
        return result;
    }
};

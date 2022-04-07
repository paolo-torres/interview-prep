// Time: O(n)
// Space: O(26)

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        
        vector<int> count(26);
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }
        
        int maxIndex = 0;
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxCount) {
                maxIndex = i;
                maxCount = count[i];
            }
        }
        if (maxCount > (n + 1) / 2) {
            return "";
        }
        
        string result = s;
        
        int i = 0;
        while (count[maxIndex] > 0) {
            result[i] = maxIndex + 'a';
            i += 2;
            count[maxIndex]--;
        }
        
        for (int j = 0; j < 26; j++) {
            while (count[j] > 0) {
                if (i >= n) {
                    i = 1;
                }
                result[i] = j + 'a';
                i += 2;
                count[j]--;
            }
        }
        
        return result;
    }
};

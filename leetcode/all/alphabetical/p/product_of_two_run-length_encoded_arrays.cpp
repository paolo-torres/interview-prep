// 2 pointers, get min freq & save product with this freq
// Push back new ans if product diff, else add to freq

// Time: O(m + n)
// Space: O(m + n)

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0;
        int j = 0;
        
        vector<vector<int>> result;
        
        while (i < encoded1.size() && j < encoded2.size()) {
            int val1 = encoded1[i][0];
            int val2 = encoded2[j][0];
            
            int freq1 = encoded1[i][1];
            int freq2 = encoded2[j][1];
            
            int currVal = val1 * val2;
            int currFreq = min(freq1, freq2);
            
            encoded1[i][1] -= currFreq;
            encoded2[j][1] -= currFreq;
            
            if (encoded1[i][1] == 0) {
                i++;
            }
            if (encoded2[j][1] == 0) {
                j++;
            }
            
            if (result.empty() || result.back()[0] != currVal) {
                result.push_back({currVal, currFreq});
            } else {
                result.back()[1] += currFreq;
            }
        }
        
        return result;
    }
};

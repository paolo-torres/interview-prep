// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());
        
        int i = 0;
        int curr = 0;
        
        while (i < weight.size()) {
            curr += weight[i];
            if (curr > 5000) {
                break;
            }
            i++;
        }
        
        return i;
    }
};

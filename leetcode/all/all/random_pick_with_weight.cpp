// Visualize number line, higher weight = more range

// Time: O(n) Solution, O(log n) pickIndex
// Space: O(n) Solution, O(1) pickIndex

class Solution {
public:
    Solution(vector<int>& w) {
        prefixSums = w;
        int prefixSum = 0;
        
        for (int i = 0; i < w.size(); i++) {
            prefixSum += w[i];
            prefixSums[i] = prefixSum;
        }
        
        totalSum = prefixSum;
    }
    
    int pickIndex() {
        double random = (double) rand() / RAND_MAX;
        double target = random * totalSum;
        
        int low = 0;
        int high = prefixSums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (target > prefixSums[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
private:
    vector<int> prefixSums;
    int totalSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

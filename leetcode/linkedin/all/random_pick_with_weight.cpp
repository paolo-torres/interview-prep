// Given array of weights, randomly pick an index where prob = w[i] / sum(w)

// Visualize number line, higher weight = more range, sampling
// Further on the number line -> higher chance -> cumulative sum
/*
    Ex. [1,2,3,4,3] -> want index 1 2/13 prob instead of equal
    [0,1,1,2,2,2,3,3,3,3,4,4,4] -> if we were to use normal rand
    i = 0: range < 1, i = 1: range < 3, i = 2, range < 6, etc.
    This above is the prefix sums, therefore this approach works
*/

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

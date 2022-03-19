// Hash map {prefix sum, count}, prefix sum + k = sum

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        
        int sum = 0;
        int diff = 0;
        
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            diff = sum - k;
            
            if (prefixSums.find(diff) != prefixSums.end()) {
                result += prefixSums[diff];
            }
            prefixSums[sum]++;
        }
        
        return result;
    }
};

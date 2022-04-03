// Prefix sum + hash map, works b/c subarray contiguous
// Ex. prefix[10] - prefix[2] = sum from index 3 to 10

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> m;
        
        int result = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            // check if nums seen so far sum to k
            if (prefixSum == k) {
                result = i + 1;
            }
            
            // if subarray seen so far sums to k, update
            int complement = prefixSum - k;
            if (m.find(complement) != m.end()) {
                result = max(result, i - m[complement]);
            }
            
            // only add prefix sum if not yet exists
            if (m.find(prefixSum) == m.end()) {
                m[prefixSum] = i;
            }
        }
        
        return result;
    }
};

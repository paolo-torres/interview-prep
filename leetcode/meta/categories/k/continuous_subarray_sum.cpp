// Hash map {running sum mod k -> index}, if seen again return true
// Ex. nums = [23,2,4,6,7], sums = [23,25,31,35,42], remainders = [5,1,1,5,0]
// Remainder 5 at indices 0 & 3, means must've added multiples of k

// Time: O(n)
// Space: O(n)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            runningSum %= k;
            
            if (m.find(runningSum) != m.end()) {
                int prev = m[runningSum];
                if (i - prev >= 2) {
                    return true;
                }
            } else {
                m[runningSum] = i;
            }
        }
        
        return false;
    }
};

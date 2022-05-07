/*
    Given nums array & an int k, return # of subarrays sum = k
    Ex. nums = [1,1,1] k = 2 -> 2, nums = [1,2,3] k = 3 -> 2

    Prefix sums, for each i, loop j = i & get sums -> optimize:
    Hash map {prefix sum, count}, prefix sum + k = sum

    Time: O(n)
    Space: O(n)
*/

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int result = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int sum = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 sum += nums[j];
//                 if (sum == k) {
//                     result++;
//                 }
//             }
//         }
//         return result;
//     }
// };

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

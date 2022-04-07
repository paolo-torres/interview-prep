// Count # of incr in nums1 & # of decr in nums2
// Start from 5 (greedy), add to sum1, repeat till equal

// Time: O(m + n)
// Space: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m * 6 < n || m > n * 6) {
            return -1;
        }
        
        int sum1 = 0;
        for (int i = 0; i < m; i++) {
            sum1 += nums1[i];
        }
        int sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum2 += nums2[i];
        }
        if (sum1 > sum2) {
            return minOperations(nums2, nums1);
        }
        
        vector<int> count(6);
        for (int i = 0; i < m; i++) {
            count[6 - nums1[i]]++;
        }
        for (int i = 0; i < n; i++) {
            count[nums2[i] - 1]++;
        }
        
        int i = 5;
        int result = 0;
        
        while (sum1 < sum2) {
            while (count[i] == 0) {
                i--;
            }
            sum1 += i;
            count[i]--;
            result++;
        }
        
        return result;
    }
};

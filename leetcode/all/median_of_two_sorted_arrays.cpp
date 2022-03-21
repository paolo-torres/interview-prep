// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation

// Time: O(log min(m, n))
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int total = m + n;
        
        int low = 0;
        int high = m;
        
        double result = 0.0;
        
        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (total + 1) / 2 - i;
            
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];
            
            if (left1 > right2) {
                high = i - 1;
            } else if (left2 > right1) {
                low = i + 1;
            } else {
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    result = max(left1, left2);
                }
                break;
            }
        }
        
        return result;
    }
};

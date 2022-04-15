// Given 2 sorted 0-indexed int arrays & int k, return kth (1-based) smallest product
// Ex. nums1 = [2,5], nums2 = [3,4], k = 2 -> output = 8, (2x3) vs (2x4), 2nd smallest = 8

// Use binary search on answer, let check(x) be how many products are <= x
// Then use binary search & find first index where we have exactly k such nums

// Time: O(n x log m x log N) -> n = len(nums1), m = len(nums2), N = 1e10
// Space: O(1)

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10;
        long long high = 1e10;
        
        long long result = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(nums1, nums2, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
private:
    bool check(vector<int>& nums1, vector<int>& nums2, long long k, long long midVal) {
        long long count = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long val = nums1[i];
            // if val = 0, product of val & any element will be 0
            // if midVal >= 0, since all products = 0, all will be <= midVal
            // so can add all products in the answer
            if (val == 0 && midVal >= 0) {
                count += nums2.size();
            } else if (val > 0) {
                count += findMaxIndex(nums2, midVal, val);
            } else if (val < 0) {
                count += findMinIndex(nums2, midVal, val);
            }
        }
        if (count >= k) {
            return true;
        }
        return false;
    }

    int findMaxIndex(vector<int>& nums2, long long midVal, long long val) {
        int low = 0;
        int high = nums2.size() - 1;
        int result = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (val * nums2[mid] <= midVal) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result + 1;
    }
    
    int findMinIndex(vector<int>& nums2, long long midVal, long long val) {
        int low = 0;
        int high = nums2.size() - 1;
        int result = high + 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (val * nums2[mid] <= midVal) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return nums2.size() - result;
    }
};

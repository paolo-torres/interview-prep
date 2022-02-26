// https://leetcode.com/problems/count-of-range-sum/discuss/77992/C%2B%2B-merge-sort-solution-very-short

// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        return mergeSort(sum, lower, upper, 0, n + 1);
    }
private:
    int mergeSort(vector<long>& sum, int lower, int upper, int low, int high) {
        if (high - low <= 1) {
            return 0;
        }
        
        int mid = low + (high - low) / 2;
        int m = mid;
        int n = mid;
        
        int count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
        
        for (int i = low; i < mid; i++) {
            while (m < high && sum[m] - sum[i] < lower) {
                m++;
            }
            while (n < high && sum[n] - sum[i] <= upper) {
                n++;
            }
            count += n - m;
        }
        
        inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
        return count;
    }
};

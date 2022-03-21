// https://leetcode.com/problems/sliding-window-median/discuss/96340/O(n-log-k)-C%2B%2B-using-multiset-and-updating-middle-iterator

// Time: O(n log k)
// Space: O(k)

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        auto mid = next(window.begin(), k / 2);
        
        vector<double> result;
        
        for (int i = k; i <= nums.size(); i++) {
            if (k % 2 == 0) {
                auto pre = prev(mid, 1);
                result.push_back(*pre + (double(*mid) - *pre) / 2.0);
            } else {
                result.push_back(*mid);
            }
            
            if (i == nums.size()) {
                break;
            }
            
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                mid--;
            }
            
            if (nums[i - k] <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(nums[i - k]));
        }
        
        return result;
    }
};

/*
    Given int array & an int k, there's a sliding window of size k moving from left to right
    If moves right by 1 pos each time, return median array for each window in original array
    Ex. nums = [1,3,-1,-3,5,3,6,7], k = 3 -> [1,-1,-1,3,5,6], middle number of each window
               |      | -> 1
                 |       | -> -1
                   |       | -> -1

    Sort window everytime -> maintain multiset as window + mid pointer, adjust as we go

    Time: O(n log k) -> optimized from O(n x k log k)
    Space: O(k)
*/

// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         vector<double> result;
//         for (int i = 0; i + k <= nums.size(); i++) {
//             vector<int> window(nums.begin() + i, nums.begin() + i + k);
//             sort(window.begin(), window.end());
//             if (k % 2 == 0) {
//                 double mid1 = window[k / 2 - 1];
//                 double mid2 = window[k / 2];
//                 result.push_back((mid1 + mid2) / 2.0);
//             } else {
//                 result.push_back(window[k / 2]);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        
        vector<double> result;
        
        for (int i = k; i <= nums.size(); i++) {
            // push current median (2 mid nums if even, 1 mid num if odd)
            if (k % 2 == 0) {
                auto pre = prev(mid, 1);
                result.push_back(*pre + (double(*mid) - *pre) / 2.0);
            } else {
                result.push_back(*mid);
            }
            
            // done (i is the end of the window)
            if (i == nums.size()) {
                break;
            }
            
            // insert incoming element
            window.insert(nums[i]);
            if (nums[i] < *mid) {
                mid--;
            }
            // remove outgoing element
            if (nums[i - k] <= *mid) {
                mid++;
            }
            window.erase(window.lower_bound(nums[i - k]));
        }
        
        return result;
    }
};

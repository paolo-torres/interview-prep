/*
    Given 2 num arrays, return array of their intersection, must be unique
    Ex. nums1 = [1,2,2,1], nums2 = [2,2] -> 2

    Hash set, add all from nums1, loop thru nums2, if exists add & remove

    Time: O(m + n)
    Space: O(m)
*/

// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s;
//         sort(nums2.begin(), nums2.end());
//         for (int i = 0; i < nums1.size(); i++) {
//             if (binarySearch(nums2, nums1[i])) {
//                 s.insert(nums1[i]);
//             }
//         }
//         vector<int> result;
//         for (auto it = s.begin(); it != s.end(); it++) {
//             result.push_back(*it);
//         }
//         return result;
//     }
// private:
//     bool binarySearch(vector<int>& nums2, int target) {
//         int low = 0;
//         int high = nums2.size() - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (nums2[mid] == target) {
//                 return true;
//             }
//             if (nums2[mid] < target) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (s.find(nums2[i]) != s.end()) {
                result.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return result;
    }
};

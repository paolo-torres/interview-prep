/*
    Given 2 num arrays, return array of their intersection, must be unique
    Ex. nums1 = [1,2,2,1], nums2 = [2,2] -> 2

    Hash set, add all from nums1, loop thru nums2, if exists add & remove

    Time: O(m + n)
    Space: O(m)
*/

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

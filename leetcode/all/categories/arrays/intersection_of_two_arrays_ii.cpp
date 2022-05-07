/*
    Given 2 num arrays, return array of their intersection
    Ex. nums1 = [1,2,2,1], nums2 = [2,2] -> [2,2]

    Hash map counter, can also do sort + 2 pointers

    Time: O(m + n)
    Space: O(m)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // {num -> count}
        unordered_map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (m[nums2[i]] > 0) {
                m[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
        return result;
    }
};

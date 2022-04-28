/*
    Given 2 sorted int arrays, merge into a single sorted array
    Ex. nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 -> [1,2,2,3,5,6]

    2 pointers, start from end, write min(p1, p2) into i, decrement

    Time: O(m + n)
    Space: O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        
        for (int i = m + n - 1; i >= 0; i--) {
            if (p2 < 0) {
                break;
            }
            
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[i] = nums1[p1];
                p1--;
            } else {
                nums1[i] = nums2[p2];
                p2--;
            }
        }
    }
};

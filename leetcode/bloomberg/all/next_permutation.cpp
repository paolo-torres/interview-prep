/*
    Next lexicographically greater permutation, find it
    Ex. nums = [1,2,3] -> [1,3,2], nums = [3,2,1] -> [1,2,3]

    From end: find first decrease, find first greater
    Swap, reverse suffix

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int j = n - 1;
        while (i < j && nums[i] >= nums[j]) {
            j--;
        }
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

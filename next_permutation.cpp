class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int i = nums.size() - 1;
        while (i > 0) {
            if (nums[i-1] < nums[i]) {
                break;
            } else {
                i--;
            }
        }
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        int j = nums.size() - 1;
        while (j > i) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
                break;
            } else {
                j--;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

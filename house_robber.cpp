class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        vector<int> result(n);
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            result[i] = max(nums[i] + result[i-2], result[i-1]);
        }
        return result[n-1];
    }
};

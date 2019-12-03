class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        if (nums.size() == 1) {
            return result;
        }
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            temp = max(nums[i], temp + nums[i]);
            result = max(result, temp);
        }
        return result;
    }
};

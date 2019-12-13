class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int temp = nums[0];
        int result = temp;
        for (int i = 1; i < nums.size(); i++) {
            temp = max(nums[i], temp + nums[i]);
            result = max(result, temp);
        }
        return result;
    }
};

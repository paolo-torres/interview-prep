class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int temp = INT_MAX;
        int result = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < temp) {
                    temp = abs(sum - target);
                    result = sum;
                }
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return result;
                }
            }
        }
        return result;
    }
};

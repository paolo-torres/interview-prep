class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                result = nums[i];
                break;
            }
        }
        return result;
    }
};

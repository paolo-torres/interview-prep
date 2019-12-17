class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) {
            return false;
        }
        if (nums.size() == 1) {
            return true;
        }
        int i = 0;
        while (i < nums.size() - 1) {
            if (i + nums[i] >= nums.size() - 1) {
                return true;
            }
            if (nums[i] == 0) {
                return false;
            }
            int maxIndex = i + 1;
            int maxValue = 0;
            for (int j = i + 1; j < i + 1 + nums[i]; j++) {
                if (j + nums[j] > maxValue) {
                    maxIndex = j;
                    maxValue = j + nums[j];
                }
            }
            i = maxIndex;
        }
        return false;
    }
};

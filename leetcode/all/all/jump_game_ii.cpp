class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int i = 0;
        int result = 0;
        while (i < nums.size() - 1) {
            if (i + nums[i] >= nums.size() - 1) {
                result++;
                break;
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
            result++;
        }
        return result;
    }
};

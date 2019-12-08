class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        bool inArray = false;
        int result = 0;
        while (i < nums.size()) {
            if (nums[i] != i) {
                inArray = true;
                result = i;
                break;
            }
            i++;
        }
        if (!inArray) {
            result = i;
        }
        return result;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        int result = 0;
        for (int i = 0; i < nums.size() + 1; i++) {
            if (s.find(i) == s.end()) {
                result = i;
                break;
            }
        }
        return result;
    }
};

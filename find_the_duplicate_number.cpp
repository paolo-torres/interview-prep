class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        unordered_set<int> s;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.find(nums[i]);
            if (it != s.end()) {
                result = *it;
                break;
            } else {
                s.insert(nums[i]);
            }
        }
        return result;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                result = nums[i];
                break;
            } else {
                s.insert(nums[i]);
            }
        }
        return result;
    }
};

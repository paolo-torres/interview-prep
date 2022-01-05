class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> m;
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                it->second++;
                if (it->second > n / 2) {
                    result = it->first;
                    break;
                }
            } else {
                m.insert({nums[i], 1});
            }
        }
        return result;
    }
};

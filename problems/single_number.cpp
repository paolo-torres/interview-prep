class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            auto it = m.find(nums[i]);
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert({nums[i], 1});
            }
        }
        int result = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->second == 1) {
                result = it->first;
                break;
            }
        }
        return result;
    }
};

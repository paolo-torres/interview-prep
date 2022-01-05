// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = m.find(complement);
            if (it != m.end()) {
                result[0] = it->second;
                result[1] = i;
                break;
            } else {
                m.insert({nums[i], i});
            }
        }
        return result;
    }
};

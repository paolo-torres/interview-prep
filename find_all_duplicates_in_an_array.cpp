class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.find(nums[i]);
            if (it != s.end()) {
                result.push_back(*it);
            } else {
                s.insert(nums[i]);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = myMap.find(complement);
            if (it != myMap.end()) {
                result.push_back(it->second);
                result.push_back(i);
                break;
            } else {
                myMap.insert({nums[i], i});
            }
        }
        return result;
    }
};

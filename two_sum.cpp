class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            auto complement = myMap.find(value);
            if (complement != myMap.end()) {
                result.push_back(complement->second);
                result.push_back(i);
                break;
            } else {
                myMap.insert({nums[i], i});
            }
        }
        return result;
    }
};

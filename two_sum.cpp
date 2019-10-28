class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> myMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int numToAdd = target - nums[i];
            auto it = myMap.find(numToAdd);
            if (it != myMap.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            myMap.insert({nums[i], i});
        }
        return result;
    }
};

/*
    An int array original is transformed into a doubled array:
    by appending twice the value of every element & shuffling
    Given a changed array, return original if changed is doubled
    Ex. changed = [1,3,4,2,6,8] -> [1,3,4], 1x2=2, 3x2=6, 4x2=8

    Freq hash map, check if value ever appears more than its double

    Time: O(n + k log k) -> n = # of ints, k = # of unique elements
    Space: O(n)
*/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) {
            return {};
        }
        
        // {value -> how many times value appears}
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[changed[i]]++;
        }
        
        vector<int> nums;
        for (auto it = m.begin(); it != m.end(); it++) {
            nums.push_back(it->first);
        }
        sort(nums.begin(), nums.end());
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            // if there's a num that appears more than its doubled num
            if (m[num] > m[num * 2]) {
                return {};
            }
            // append to result for how many nums are present
            for (int j = 0; j < m[num]; j++) {
                result.push_back(num);
                m[num * 2]--;
            }
        }
        return result;
    }
};

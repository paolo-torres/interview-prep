// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int result = 0;
        
        for (auto it = s.begin(); it != s.end(); it++) {
            int currNum = *it;
            if (s.find(currNum - 1) == s.end()) {
                int currLength = 1;
                while (s.find(currNum + 1) != s.end()) {
                    currLength++;
                    currNum++;
                }
                result = max(result, currLength);
            }
        }
        
        return result;
    }
};

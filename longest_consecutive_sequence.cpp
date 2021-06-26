// Time: O(n)
// Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int best = 0;
        
        for (auto it = s.begin(); it != s.end(); it++) {
            int prev = *it - 1;
            if (s.find(prev) == s.end()) {
                int next = *it + 1;
                int curr = 1;
                
                while (s.find(next) != s.end()) {
                    next++;
                    curr++;
                }
                
                best = max(curr, best);
            }
        }
        
        return best;
    }
};

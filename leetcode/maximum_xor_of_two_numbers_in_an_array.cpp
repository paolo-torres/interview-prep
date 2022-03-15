// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91049/Java-O(n)-solution-using-bit-manipulation-and-HashMap

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int result = 0;
        
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            
            unordered_set<int> s;
            for (int i = 0; i < nums.size(); i++) {
                int left = nums[i] & mask;
                s.insert(left);
            }
            
            int curr = result | (1 << i);
            for (auto it = s.begin(); it != s.end(); it++) {
                int complement = *it ^ curr;
                if (s.find(complement) != s.end()) {
                    result = curr;
                    break;
                }
            }
        }
        
        return result;
    }
};

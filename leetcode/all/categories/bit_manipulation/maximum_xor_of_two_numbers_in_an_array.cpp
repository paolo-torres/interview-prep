/*
    Given nums array, return max result of nums[i] XOR nums[j]
    Ex. nums = [3,10,5,25,2,8] -> 28, 5 XOR 25 = 28

    Convert all nums to binary, construct bit by bit
    Bitwise prefixes in hash set

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int result = 0;
        
        // want largest XOR, so start from 31st position
        for (int i = 31; i >= 0; i--) {
            // 100...000, 110...000, 111...000, ..., 111...111
            mask = mask | (1 << i);
            
            unordered_set<int> s;
            for (int i = 0; i < nums.size(); i++) {
                // ex. i = 2:
                // {1100, 1000, 0100, 0000} from {1110, 1011, 0111, 0010}
                int left = nums[i] & mask;
                s.insert(left);
            }
            
            // if i = 1 before this, result is now 1100, want result
            // to become 1110, so try to get this greedy choice
            int curr = result | (1 << i);
            
            for (auto it = s.begin(); it != s.end(); it++) {
                // if a ^ b = c, then a ^ c = b
                // left ^ complement = curr
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

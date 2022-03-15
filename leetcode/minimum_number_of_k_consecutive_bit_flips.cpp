// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/discuss/239284/C%2B%2B-greedy-stack-and-O(1)-memory

// Time: O(n)
// Space: O(k)

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> isFlipped;
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (isFlipped.empty() || isFlipped.size() % 2 == 0) {
                    isFlipped.push(i + k - 1);
                    result++;
                }
            } else {
                if (isFlipped.size() % 2 != 0) {
                    isFlipped.push(i + k - 1);
                    result++;
                }
            }
            
            if (!isFlipped.empty() && i >= isFlipped.front()) {
                isFlipped.pop();
            }
        }
        
        if (isFlipped.empty()) {
            return result;
        }
        return -1;
    }
};

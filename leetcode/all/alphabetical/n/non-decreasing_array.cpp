// Greedy, nums[i - 1] > nums[i], decide how to fix

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int modify = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (modify == 1) {
                    return false;
                }
                
                // example: [1,  5,  3]
                //           i-2 i-1 i
                if (i < 2 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                // example: [4,  5,  3]
                //           i-2 i-1 i
                } else {
                    nums[i] = nums[i - 1];
                }
                
                modify++;
            }
        }
        
        return true;
    }
};

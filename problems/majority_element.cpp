// Time: O(n)
// Space: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == result) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    result = nums[i];
                    count = 1;
                }
            }
        }
        
        return result;
    }
};

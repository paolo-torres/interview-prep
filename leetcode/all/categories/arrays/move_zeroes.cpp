/*
    Given nums array, move all 0's to the end
    Ex. nums = [0,1,0,3,12] -> [1,3,12,0,0]

    Move all non-0's to front, then loop thru rest & make 0

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[start] = nums[i];
                start++;
            }
        }
        for (int i = start; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

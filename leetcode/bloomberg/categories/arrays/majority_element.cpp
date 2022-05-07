/*
    Given nums array, return majority element
    Ex. nums = [3,2,3] -> 3

    Brute force -> hash map -> sorting -> optimize:
    Voting algo: count instances of majority element

    Time: O(n)
    Space: O(1)
*/

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

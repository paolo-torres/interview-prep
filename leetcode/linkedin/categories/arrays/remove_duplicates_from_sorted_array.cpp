/*
    Given int array, remove duplicates, return size
    Ex. nums = [1,1,2] -> 2, [1,2,_]
    
    2 pointers, iterate i only if non-equal

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 1;
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

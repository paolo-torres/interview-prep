/*
    Given array of nums, return # of triplets that can make triangles
    Ex. nums = [2,2,3,4] -> 3, (2,3,4), (2,3,4), (2,2,3)

    Valid triangle: length of any side is <= sum of 2 other sides:
    a + b > c, a + c > b, b + c > a
    Sort, valid triangle if nums[i] + nums[j] > nums[k], 3 pointers

    Time: O(n^2)
    Space: O(log n) -> space complexity for C++ sort
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        
        for (int k = 2; k < nums.size(); k++) {
            int i = 0;
            int j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    result += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
};

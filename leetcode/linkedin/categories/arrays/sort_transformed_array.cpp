// Given sorted int array & 3 ints, apply quadratic function, return in sorted order
// Ex. nums = [-4,-2,2,4], a = 1, b = 3, c = 5 -> output = [3,9,15,33]

// 2 cases: (1) a >= 0 concave up, (2) a < 0 concave down

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        
        int i = 0;
        int j = n - 1;
        int index = a >= 0 ? n - 1 : 0;
        
        vector<int> result(n);
        
        while (i <= j) {
            int left = quad(nums[i], a, b, c);
            int right = quad(nums[j], a, b, c);
            // concave up
            if (a >= 0) {
                if (left >= right) {
                    result[index] = left;
                    i++;
                } else {
                    result[index] = right;
                    j--;
                }
                index--;
            // concave down
            } else {
                if (left >= right) {
                    result[index] = right;
                    j--;
                } else {
                    result[index] = left;
                    i++;
                }
                index++;
            }
        }
        
        return result;
    }
private:
    int quad(int x, int a, int b, int c) {
        return a * pow(x, 2) + b * x + c;
    }
};

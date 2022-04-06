// Hash map {val -> idx list}, optimize w/ sampling
// Each has a 1/n chance to be chosen -> count == n

// Time: O(n)
// Space: O(1)

class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    int pick(int target) {
        int count = 0;
        int result = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != target) {
                continue;
            }
            count++;
            if (rand() % count == 0) {
                result = i;
            }
        }
        
        return result;
    }
private:
    vector<int> arr;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

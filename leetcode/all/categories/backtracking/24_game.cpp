// Try every possible num/operator combo, backtracking, true if final num = 24

// Time: O(1)
// Space: O(n)

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int i = 0; i < cards.size(); i++) {
            nums.push_back((double) cards[i]);
        }
        
        double epsilon = 0.001;
        bool result = false;
        
        helper(nums, epsilon, result);
        return result;
    }
private:
    void helper(vector<double>& nums, double epsilon, bool& result) {
        if (result == true) {
            return;
        }
        if (nums.size() == 1) {
            if (abs(nums[0] - 24.0) < epsilon) {
                result = true;
            }
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                vector<double> next;
                
                double n1 = nums[i];
                double n2 = nums[j];
                
                next.insert(next.end(), {n1 + n2, n1 - n2, n2 - n1, n1 * n2});
                if (abs(n1) > epsilon) {
                    next.push_back(n2 / n1);
                }
                if (abs(n2) > epsilon) {
                    next.push_back(n1 / n2);
                }
                
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + j);
                
                for (int i = 0; i < next.size(); i++) {
                    nums.push_back(next[i]);
                    helper(nums, epsilon, result);
                    nums.pop_back();
                }
                
                nums.insert(nums.begin() + j, n2);
                nums.insert(nums.begin() + i, n1);
            }
        }
    }
};

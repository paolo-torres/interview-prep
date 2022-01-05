// Time: O(n^2)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        
        if (n < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    int jPrev = nums[j];
                    int kPrev = nums[k];
                    
                    while (j < k && nums[j] == jPrev) {
                        j++;
                    }
                    while (j < k && nums[k] == kPrev) {
                        k--;
                    }
                }
            }
        }
        
        return result;
    }
};

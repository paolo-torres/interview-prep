class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size() - 2; a++) {
            if (nums[a] > 0) {
                break;
            }
            if (a > 0 && nums[a-1] == nums[a]) {
                continue;
            }
            int b = a + 1;
            int c = nums.size() - 1;
            while (b < c) {
                int sum = nums[a] + nums[b] + nums[c];
                if (sum < 0) {
                    b++;
                } else if (sum > 0) {
                    c--;
                } else {
                    result.push_back({nums[a], nums[b], nums[c]});
                    int bPrev = nums[b];
                    int cPrev = nums[c];
                    while (b < c && nums[b] == bPrev) {
                        b++;
                    }
                    while (b < c && nums[c] == cPrev) {
                        c--;
                    }
                }
            }
        }
        return result;
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k == 0) {
            return;
        }
        reverse(nums.begin(), nums.end());
        auto pivot = nums.begin();
        k %= nums.size();
        advance(pivot, k);
        reverse(nums.begin(), pivot);
        reverse(pivot, nums.end());
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        auto it = nums.begin();
        auto nxt = next(it);
        while (nxt != nums.end()) {
            if (*it == *nxt) {
                nums.erase(nxt);
            } else {
                ++it;
                ++nxt;
            }
        }
        return nums.size();
    }
};

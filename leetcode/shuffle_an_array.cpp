class Solution {
private:
    vector<int> orig;
    vector<int> data;
public:
    Solution(vector<int>& nums) {
        orig = nums;
        data = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        data = orig;
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = 0; i < data.size(); i++) {
            int index = i + rand() % (data.size() - i);
            swap(data[i], data[index]);
        }
        return data;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

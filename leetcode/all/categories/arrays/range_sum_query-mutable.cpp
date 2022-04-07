class NumArray {
private:
    vector<int> orig;
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        orig = nums;
        sums = nums;
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i] + sums[i-1];
        }
    }
    
    void update(int i, int val) {
        int diff = orig[i] - val;
        orig[i] = val;
        for (int index = i; index < sums.size(); index++) {
            sums[index] -= diff;
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

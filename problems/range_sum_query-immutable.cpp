class NumArray {
private:
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        data = nums;
        for (int i = 1; i < nums.size(); i++) {
            data[i] = data[i] + data[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return data[j];
        } else {
            return data[j] - data[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */

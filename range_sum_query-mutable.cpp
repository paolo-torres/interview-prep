class NumArray {
private:
    vector<int> temp;
    vector<int> data;
public:
    NumArray(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        temp = nums;
        data = nums;
        for (int i = 1; i < nums.size(); i++) {
            data[i] = data[i] + data[i-1];
        }
    }
    
    void update(int i, int val) {
        int diff = temp[i] - val;
        temp[i] = val;
        for (int index = i; index < data.size(); index++) {
            data[index] -= diff;
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
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

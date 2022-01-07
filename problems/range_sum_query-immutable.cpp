// NumArray
// Time: O(n)
// Space: O(n)

// sumRange
// Time: O(1)
// Space: O(1)

class NumArray {
public:
    NumArray(vector<int>& nums) {
        data = nums;
        for (int i = 1; i < data.size(); i++) {
            data[i] += data[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return data[right];
        }
        return data[right] - data[left-1];
    }
private:
    vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

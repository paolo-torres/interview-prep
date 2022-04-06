// vector pair (index, value), ignore all 0's

// Time: O(n) SparseVector, O(l1 + l2) dotProduct
// Space: O(l) SparseVector, O(1) dotProduct

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                v.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int i = 0;
        int j = 0;
        
        int result = 0;
        
        while (i < v.size() && j < vec.v.size()) {
            if (v[i].first == vec.v[j].first) {
                result += v[i].second * vec.v[j].second;
                i++;
                j++;
            } else if (v[i].first < vec.v[j].first) {
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
private:
    vector<pair<int, int>> v;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);

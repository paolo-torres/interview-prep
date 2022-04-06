// Start from LSB, if sum > 1 carry = -1 for next iter, if -ve carry = 1 

// Time: O(max(m, n))
// Space: O(1)

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        
        int carry = 0;
        int length = max(m, n);
        
        vector<int> result;
        
        for (int i = 0; i < length || carry != 0; i++) {
            int bit1 = 0;
            int bit2 = 0;
            if (i < m) {
                bit1 = arr1[m - i - 1];
            }
            if (i < n) {
                bit2 = arr2[n - i - 1];
            }
            
            int sum = bit1 + bit2 + carry;
            result.push_back(abs(sum) % 2);
            
            if (sum < 0) {
                carry = 1;
            } else if (sum > 1) {
                carry = -1;
            } else {
                carry = 0;
            }
        }
        
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};

// Same as next permutation problem

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        
        // (1) from end, find first decrease
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            i--;
        }
        
        if (i < 0) {
            return -1;
        }
        
        // (2) find first greater element
        int j = num.size() - 1;
        while (i < j && num[i] >= num[j]) {
            j--;
        }
        
        // (3) swap & reverse suffix
        swap(num[i], num[j]);
        reverse(num.begin() + i + 1, num.end());
        
        long result = stol(num);
        if (result > INT_MAX) {
            return -1;
        }
        return result;
    }
};

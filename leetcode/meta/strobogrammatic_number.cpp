// 2 pointers, hash map of valid matches

// Time: O(n)
// Space: O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> m {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        
        int i = 0;
        int j = num.size() - 1;
        
        while (i <= j) {
            if (m.find(num[i]) == m.end()) {
                return false;
            }
            if (m[num[i]] != num[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
};

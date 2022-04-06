// bottom-up 1-D DP, memoize on cost (# of char deletions)

// Time: O(n^2)
// Space: O(n)

class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<int> memo(n, 0);
        
        int temp = 0;
        int prev = 0;
        
        // generate all combos of 'i' & 'j' in order
        for (int i = n - 2; i >= 0; i--) {
            // stores value at memo[i + 1][j - 1]
            prev = 0;
            
            for (int j = i + 1; j < n; j++) {
                // store value at memo[i + 1][j] temporarily
                temp = memo[j];
                
                // case 1: char at 'i' equals char at 'j'
                if (s[i] == s[j]) {
                    memo[j] = prev;
                // case 2: char at 'i' doesn't equal char at 'j'
                // either delete char at 'i' or char at 'j'
                // take min & add 1 for cost of deletion
                } else {
                    // memo[j] contains value for memo[i + 1][j]
                    // memo[j - 1] contains value for memo [i][j - 1]
                    memo[j] = 1 + min(memo[j], memo[j - 1]);
                }
                
                // copy value of memo[i + 1][j] to 'prev'
                prev = temp;
            }
        }
        
        if (memo[n - 1] <= k) {
            return true;
        }
        return false;
    }
};

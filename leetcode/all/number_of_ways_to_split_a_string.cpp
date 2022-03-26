// 1st cut at ones / 3, 2nd cut at 2 * ones / 3

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numWays(string s) {
        int m = pow(10, 9) + 7;
        int n = s.size();
        int ones = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ones++;
            }
        }
        
        if (ones % 3 != 0) {
            return 0;
        }
        if (ones == 0) {
            return (int)(n - 2L) * (n - 1L) / 2 % m;
        }
        
        int onesInEachBlock = ones / 3;
        int count = 0;
        
        long waysFirstCut = 0;
        long waysSecondCut = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
            }
            if (count == onesInEachBlock) {
                waysFirstCut++;
            } else if (count == 2 * onesInEachBlock) {
                waysSecondCut++;
            }
        }
        
        
        return (int)(waysFirstCut * waysSecondCut % m);
    }
};

// Array w/ seen remainder freqs, find valid pairs
// (a + b) % 60 = 0 -> a % 60 = 0 AND b % 60 = 0, OR
//                     (a % 60) + (b % 60) = 60

// Time: O(n)
// Space: O(1)

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainders(60);
        int result = 0;
        
        for (int i = 0; i < time.size(); i++) {
            int remainder = time[i] % 60;
            
            // check if: a % 60 = 0 AND b % 60 = 0
            if (remainder == 0) {
                result += remainders[0];
            // check if: (a % 60) + (b % 60) = 60
            // =>        b % 60 = 60 - (a % 60)
            } else {
                result += remainders[60 - remainder];
            }
            
            // update remainders seen
            remainders[remainder]++;
        }
        
        return result;
    }
};

// Time: O(n)
// Space: O(1)

class Solution {
public:
    string toHexspeak(string num) {
        long val = stol(num);
        long remainder = 0;
        
        unordered_map<long, char> m {
            {0, 'O'},
            {1, 'I'},
            {10, 'A'},
            {11, 'B'},
            {12, 'C'},
            {13, 'D'},
            {14, 'E'},
            {15, 'F'}
        };
        
        string result;
        
        while (val > 0) {
            remainder = val % 16;
            if (remainder > 1 && remainder < 10) {
                return "ERROR";
            }
            val = val / 16;
            result.push_back(m[remainder]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

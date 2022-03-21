class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1) {
                result += m[s[i]];
            } else if (s[i] == 'I' && s[i+1] == 'V' || s[i] == 'I' && s[i+1] == 'X') {
                result += m[s[i+1]] - m[s[i]];
                i++;
            } else if (s[i] == 'X' && s[i+1] == 'L' || s[i] == 'X' && s[i+1] == 'C') {
                result += m[s[i+1]] - m[s[i]];
                i++;
            } else if (s[i] == 'C' && s[i+1] == 'D' || s[i] == 'C' && s[i+1] == 'M') {
                result += m[s[i+1]] - m[s[i]];
                i++;
            } else {
                result += m[s[i]];
            }
        }
        return result;
    }
};

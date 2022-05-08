/*
    Given a roman numeral, convert it to an integer
    Ex. s = "III" -> 3, s = "LVIII" -> 58, s = "MCMXCIV" -> 1994

    Largest to smallest add up, smaller before larger subtract smaller

    Time: O(1)
    Space: O(1)
*/

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
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
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && m[s[i]] < m[s[i + 1]]) {
                result -= m[s[i]];
            } else {
                result += m[s[i]];
            }
        }
        return result;
    }
};

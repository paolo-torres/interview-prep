/*
    Given an integer, convert it to a roman numeral
    Ex. num = 3 -> "III", num = 58 -> "LVIII", num = 1994 -> "MCMXCIV"

    Greedy, try bigger values first, divide to determine # of uses

    Time: O(1)
    Space: O(1)
*/

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> v = {
            {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9},
            {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90},
            {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900},
            {"M", 1000}
        };
        
        string result = "";
        for (int i = v.size() - 1; i >= 0; i--) {
            string sym = v[i].first;
            int val = v[i].second;
            if (num / val) {
                int count = num / val;
                for (int j = 0; j < count; j++) {
                    result += sym;
                }
                num = num % val;
            }
        }
        return result;
    }
};

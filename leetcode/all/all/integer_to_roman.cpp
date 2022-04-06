class Solution {
public:
    string intToRoman(int num) {
        map <int, char> m = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        int exponent = 0;
        if (num > 0 && num < 10) {
            exponent = 0;
        } else if (num >= 10 && num < 100) {
            exponent = 1;
        } else if (num >= 100 && num < 1000) {
            exponent = 2;
        } else if (num >= 1000 && num < 4000) {
            exponent = 3;
        }
        string result;
        while (num != 0) {
            int multiplier = pow(10, exponent);
            int temp = ((num / multiplier) % 10) * multiplier;
            num -= temp;
            exponent--;
            if (temp == 4) {
                result.append("IV");
            } else if (temp == 9) {
                result.append("IX");
            } else if (temp == 40) {
                result.append("XL");
            } else if (temp == 90) {
                result.append("XC");
            } else if (temp == 400) {
                result.append("CD");
            } else if (temp == 900) {
                result.append("CM");
            } else {
                auto it = m.find(temp);
                if (it != m.end()) {
                    result.push_back(it->second);
                } else {
                    while (temp != 0) {
                        it = m.begin();
                        while (temp >= it->first && next(it) != m.end()) {
                            ++it;
                        }
                        if (temp < it->first) {
                            it = prev(it);
                        }
                        result.push_back(it->second);
                        temp -= it->first;
                    }
                }
            }
        }
        return result;
    }
};

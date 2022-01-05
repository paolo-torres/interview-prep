class Solution {
public:
    int myAtoi(string str) {
        if (str.size() == 0) {
            return 0;
        }
        int result = 0;
        bool isNegative = false;
        auto it = str.begin();
        while (it != str.end()) {
            if (*it == ' ') {
                ++it;
                continue;
            } else if (*it == '+') {
                isNegative = false;
                ++it;
            } else if (*it == '-') {
                isNegative = true;
                ++it;
            } else if (!isdigit(*it)) {
                return 0;
            }
            while (it != str.end()) {
                if (isdigit(*it)) {
                    if (!isNegative
                        && (result + (*it - '0')) >= (INT_MAX / 10) + 7) {
                        return INT_MAX;
                    } else if (isNegative
                        && (-result - (*it - '0')) <= (INT_MIN / 10) - 8) {
                        return INT_MIN;
                    } else {
                        result = result * 10 + (*it - '0');
                    }
                    ++it;
                } else {
                    it = str.end();
                }
            }
        }
        if (isNegative) {
            return -result;
        } else {
            return result;
        }   
    }
};

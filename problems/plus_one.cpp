class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i] = digits[i] + 1;
        if (digits[i] >= 10) {
            int carry = 1;
            digits[i] %= 10;
            i--;
            while (i >= 0 && carry == 1) {
                digits[i] = digits[i] + carry;
                if (digits[i] >= 10) {
                    digits[i] %= 10;
                    i--;
                } else {
                    carry = 0;
                }
            }
            if (carry == 1) {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};

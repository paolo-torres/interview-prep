/*
    Convert a non-negative integer num to its English words representation

    Group nums by 1's & 10's naming, compute w/ divide + name + remainder

    Time: O(1)
    Space: O(n)
*/

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return helper(num).substr(1);
    }
private:
    vector<string> ones = {
        "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"
    };
    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy",
        "Eighty", "Ninety"
    };

    string helper(int num) {
        if (num >= 1000000000) {
            return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
        }
        if (num >= 1000000) {
            return helper(num / 1000000) + " Million" + helper(num % 1000000);
        }
        if (num >= 1000) {
            return helper(num / 1000) + " Thousand" + helper(num % 1000);
        }
        if (num >= 100) {
            return helper(num / 100) + " Hundred" + helper(num % 100);
        }
        if (num >= 20) {
            return " " + tens[num / 10] + helper(num % 10);
        }
        if (num >= 1) {
            return " " + ones[num];
        }
        return "";
    }
};

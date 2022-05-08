/*
    Given 2 nums as strings, return sum w/o direct conversion
    Ex. num1 = "11", num2 = "123" -> "134"

    2 pointers, start from end, get sum, maintain carry

    Time: O(max(m, n))
    Space: O(max(m, n))
*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        int carry = 0;
        string result = "";
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            
            sum += carry;
            carry = sum / 10;
            sum %= 10;
            
            result += to_string(sum);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

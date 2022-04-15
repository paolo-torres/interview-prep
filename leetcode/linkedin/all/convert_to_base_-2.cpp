// Given int, return binary string in base -2

// Same as normal base 2 conversion except negative

// Time: O(log n)
// Space: O(log n)

class Solution {
public:
    string baseNeg2(int n) {
        string result = "";
        
        while (n != 0) {
            int remainder = n % 2;
            n /= -2;
            /*
                nPrev = nCurr * -2 + remainder
                since remainder - (-2) -> nCurr * (-2) + (remainder - (-2))
                to account for -2 dropped from remainder, do +1 to n
                finally (nCurr + 1) * (-2) + (remainder - (-2)) = nCurr * (-2) + remainder
            */
            if (remainder < 0) {
                remainder += 2;
                n++;
            }
            result = to_string(remainder) + result;
        }
        
        if (result == "") {
            return "0";
        }
        return result;
    }
};

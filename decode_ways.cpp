class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 1;
        int result = first + second;
        for (int i = 2; i <= n; i++) {
            int firstTemp = first * ((s[i-2] == '1') || (s[i-2] == '2' && s[i-1] <= '6'));
            int secondTemp = second * (s[i-1] != '0');
            result = firstTemp + secondTemp;
            first = second;
            second = result;
        }
        return result;
    }
};

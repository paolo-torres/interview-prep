// Stack, if '[' push curr, if ']' process curr

// Time: O(n x max(k)) -> length of string x max value of k
// Space: O(n)

class Solution {
public:
    string decodeString(string s) {
        // k[encoded string]
        stack<string> chars;
        stack<int> nums;
        
        int k = 0;
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            // if digit, convert string number to integer
            if (isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
            // if letter, simply add to our result
            } else if (isalpha(s[i])) {
                result += s[i];
            // if open bracket, store curr string & num
            } else if (s[i] == '[') {
                chars.push(result);
                nums.push(k);
                
                // reset to default since restarts in bracket
                result = "";
                k = 0;
            // if close bracket, start processing k[encoded string]
            } else if (s[i] == ']') {
                string temp = result;
                
                for (int i = 0; i < nums.top() - 1; i++) {
                    result += temp;
                }
                result = chars.top() + result;
                
                chars.pop();
                nums.pop();
            }
        }
        
        return result;
    }
};

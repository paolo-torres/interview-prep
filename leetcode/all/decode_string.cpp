class Solution {
public:
    string decodeString(string s) {
        stack<string> chars;
        stack<int> nums;
        int num = 0;
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (isalpha(s[i])) {
                result.push_back(s[i]);
            } else if (s[i] == '[') {
                chars.push(result);
                nums.push(num);
                result = "";
                num = 0;
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

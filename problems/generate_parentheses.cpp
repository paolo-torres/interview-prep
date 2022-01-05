class Solution {
private:
    void generate(int left, int right, string str, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }
        if (left > 0) {
            generate(left - 1, right, str + '(', result);
        }
        if (left < right) {
            generate(left, right - 1, str + ')', result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, "", result);
        return result;
    }
};

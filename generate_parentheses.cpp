class Solution {
private:
    vector<string> result;
    void makeCombos(int left, int right, string str) {
        if (left == 0 && right == 0) {
            result.push_back(str);
            return;
        }
        if (left > 0) {
            makeCombos(left - 1, right, str + "(");
        }
        if (left < right) {
            makeCombos(left, right - 1, str + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        makeCombos(n, n, "");
        return result;
    }
};

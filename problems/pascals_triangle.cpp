class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int>> result(numRows);
        if (numRows == 0) {
            return result;
        }
        result[0].push_back(1);
        if (numRows == 1) {
            return result;
        }
        result[1].push_back(1);
        result[1].push_back(1);
        if (numRows == 2) {
            return result;
        }
        for (int i = 2; i < numRows; i++) {
            temp.push_back(1);
            for (int j = 1; j < i; j++) {
                int sum = result[i-1][j] + result[i-1][j-1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            result[i] = temp;
            temp.clear();
        }
        return result;
    }
};

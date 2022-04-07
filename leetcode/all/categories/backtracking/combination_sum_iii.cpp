// Time: O(2^n)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> result;
        findCombos(k, n, 0, 1, curr, result);
        return result;
    }
private:
    void findCombos(int k, int n, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (curr.size() > k || sum > n) {
            return;
        }
        if (curr.size() == k && sum == n) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            findCombos(k, n, sum + i, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

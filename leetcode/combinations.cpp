// Time: O(n^k)
// Space: O(k)

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        vector<vector<int>> result;
        findCombos(n, k, 1, curr, result);
        return result;
    }
private:
    void findCombos(int n, int k, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i <= n; i++) {
            curr.push_back(i);
            findCombos(n, k, i + 1, curr, result);
            curr.pop_back();
        }
    }
};

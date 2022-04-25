/*
    Given int array & a difference, return length of longest subsequence:
    such that the diff b/w adj elements in the subsequence = difference
    Ex. arr = [1,2,3,4], difference = 1 -> 4, [1,2,3,4]

    At each int, consider it as end of sequence, check length of this
    DP, recurrence relation: dp[i] = max(dp[i], dp[i - difference] + 1)

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int result = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            if (m.find(arr[i] - difference) != m.end()) {
                m[arr[i]] = m[arr[i] - difference] + 1;
            } else {
                m[arr[i]] = 1;
            }
            result = max(result, m[arr[i]]);
        }
        
        return result;
    }
};

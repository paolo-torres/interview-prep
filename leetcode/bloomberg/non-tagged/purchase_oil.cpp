/*
    'm' amount of oil can be purchased from 'n' companies. Every
    company has 'k' capacity of oil to be sold, you can take zero
    or many times the quantity offered by each company. Give the
    maximum number of combinations possible.
    Ex. A - 10, B - 15, C - 50, target = 60
    Number of combinations: 4, [[10,50],[15,45],[20,40],[10,20,30]]
    
    Same as Coin Change 2, either try & stay at idx, or don't try & proceed

    Time: O(m x n) -> m = # of companies, n = amount
    Space: O(m x n) -> optimize to O(n)
*/

#include <stdio.h>

#include <iostream>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int numberOfCombos(int amount, vector<int>& nums) {
//         return dfs(amount, nums, 0, 0);
//     }
// private:
//     // {(index, sum) -> # of combos that make up this amount}
//     map<pair<int, int>, int> dp;
//     int dfs(int amount, vector<int>& nums, int i, int sum) {
//         if (sum == amount) {
//             return 1;
//         }
//         if (sum > amount) {
//             return 0;
//         }
//         if (i == nums.size()) {
//             return 0;
//         }
//         if (dp.find({i, sum}) != dp.end()) {
//             return dp[{i, sum}];
//         }
//         dp[{i, sum}] = dfs(amount, nums, i, sum + nums[i])
//                      + dfs(amount, nums, i + 1, sum);  
//         return dp[{i, sum}];
//     }
// };

class Solution {
public:
    int numberOfCombos(int amount, vector<int>& nums) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j < amount + 1; j++) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[amount];
    }
};

int main() {
    int amount = 60;
    vector<int> nums = {10, 15, 50};
    Solution* obj = new Solution();

    int result = obj->numberOfCombos(amount, nums);
    cout << result << endl;

    return 0;
}

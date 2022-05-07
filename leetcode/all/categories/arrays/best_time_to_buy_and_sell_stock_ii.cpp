/*
    Given prices array, on each day may buy or sell
    Can only hold at most 1 share, find max profit
    Ex. prices = [7,1,5,3,6,4] -> 7, (5-1) + (6-3) = 7

    Peak valley -> simple 1 pass just add incremental profits

    Time: O(n)
    Space: O(1)
*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int i = 0;
//         int valley = prices[0];
//         int peak = prices[0];
//         int result = 0;
//         while (i < n - 1) {
//             while (i < n - 1 && prices[i] >= prices[i + 1]) {
//                 i++;
//             }
//             valley = prices[i];
//             while (i < n - 1 && prices[i] <= prices[i + 1]) {
//                 i++;
//             }
//             peak = prices[i];
//             result += peak - valley;
//         }
//         return result;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                result += prices[i] - prices[i-1];
            }
        }
        return result;
    }
};

// For each turn, count k & remove from list

// Time: O(n)
// Space: O(n)

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> friends;
        for (int i = 0; i < n; i++) {
            friends.push_back(i + 1);
        }
        
        int i = 0;
        while (friends.size() > 1) {
            i = (i + k - 1) % friends.size();
            friends.erase(friends.begin() + i);
            i = i % friends.size();
        }
        
        return friends[0];
    }
};

// // n = 1 -> winner = 0
// // n = 2 -> winner = (0 + k) % 2
// // n = 3 -> winner = (f(2) + 2) % 3
// // n = n -> winner = (f(n - 1) + k) % n

// // Time: O(n)
// // Space: O(1)

// class Solution {
// public:
//     int findTheWinner(int n, int k) {
//         int result = 0;
//         for (int i = 1; i <= n; i++) {
//             result = (result + k) % i;
//         }
//         return result + 1;
//     }
// };

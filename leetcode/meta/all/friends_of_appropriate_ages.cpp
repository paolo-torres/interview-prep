// Hash map for optimal, if no age constraint, binary search optimal

// // Time: O(n) -> 1 <= ages[i] <= 120, 121 * 121 = O(14641) = O(1)
// // Space: O(1)

// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         unordered_map<int, int> count;
//         for (int i = 0; i < ages.size(); i++) {
//             count[ages[i]]++;
//         }
        
//         int result = 0;
        
//         for (auto x = count.begin(); x != count.end(); x++) {
//             for (auto y = count.begin(); y != count.end(); y++) {
//                 int xPerson = x->first;
//                 int yPerson = y->first;
                
//                 int xCount = x->second;
//                 int yCount = y->second;
                
//                 if (canSend(xPerson, yPerson)) {
//                     if (xPerson == yPerson) {
//                         result += xCount * (yCount - 1);
//                     } else {
//                         result += xCount * yCount;
//                     }
//                 }
//             }
//         }
        
//         return result;
//     }
// private:
//     bool canSend(int x, int y) {
//         return !(y <= 0.5 * x + 7 || y > x || (y > 100 && x < 100));
//     }
// };

// Time: O(n log n)
// Space: O(1)

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int result = 0;
        
        for (int i = 0; i < ages.size(); i++) {
            int lower = helper(ages, ages[i] / 2 + 7);
            int upper = helper(ages, ages[i]);
            result += max(upper - lower - 1, 0);
        }
        
        return result;
    }
private:
    int helper(vector<int>& ages, int target) {
        int low = 0;
        int high = ages.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (ages[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
};

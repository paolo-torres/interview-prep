/*
    Given list of times, return min minutes b/w any 2 times
    Ex. timePoints = ["23:59","00:00"] -> 1

    Sort + compare diffs -> optimize w/ bool array to track seen times, compare

    Time: O(n)
    Space: O(1)
*/

// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         int n = timePoints.size();
//         sort(timePoints.begin(), timePoints.end());
//         int result = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             int diff = abs(helper(timePoints[(i - 1 + n) % n], timePoints[i]));
//             diff = min(diff, 1440 - diff);
//             result = min(result, diff);
//         }
//         return result;
//     }
// private:
//     int helper(string& s1, string& s2) {
//         int h1 = stoi(s1.substr(0, 2));
//         int m1 = stoi(s1.substr(3, 2));
//         int h2 = stoi(s2.substr(0, 2));
//         int m2 = stoi(s2.substr(3, 2));
//         return (h2 - h1) * 60 + (m2 - m1);
//     }
// };

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // there's only 24 * 60 = 1440 possible time points
        int n = 24 * 60;
        
        // mark seen time points
        vector<bool> v(n);
        for (int i = 0; i < timePoints.size(); i++) {
            string time = timePoints[i];
            int curr = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
            if (v[curr]) {
                return 0;
            }
            v[curr] = true;
        }
        
        int diff = INT_MAX;
        int pre = -1;
        int first = INT_MAX;
        int last = INT_MIN;
        
        // store min diff between seen time points
        for (int i = 0; i < n; i++) {
            if (v[i]) {
                if (pre != -1) {
                    diff = min(diff, min(i - pre, pre + n - i));
                }
                first = min(first, i);
                last = max(last, i);
                pre = i;
            }
        }
        
        return min(diff, min(last - first, first + n - last));
    }
};

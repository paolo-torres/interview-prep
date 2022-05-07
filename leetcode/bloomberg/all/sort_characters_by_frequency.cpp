/*
    Given a string, sort in decr order of freq, return string
    Ex. s = "tree" -> "eert", s = "cccaaa" -> "aaaccc"

    Hash map + max heap -> optimize w/ freq bucket sort

    Time: O(n log n) -> optimize to O(n)
    Space: O(n)
*/

// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> m;
//         for (int i = 0; i < s.size(); i++) {
//             m[s[i]]++;
//         }
//         priority_queue<pair<int, char>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//         }
//         string result;
//         while (!pq.empty()) {
//             int count = pq.top().first;
//             char letter = pq.top().second;
//             while (count > 0) {
//                 result += letter;
//                 count--;
//             }
//             pq.pop();
//         }
//         return result;
//     }
// };

class Solution {
public:
    string frequencySort(string s) {
        // count occurrences {char -> count}
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        int maxFreq = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            maxFreq = max(maxFreq, it->second);
        }
        
        // make list of buckets and apply bucket sort
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            char c = it->first;
            int freq = it->second;
            buckets[freq].push_back(c);
        }
        
        // build string
        string result = "";
        for (int i = buckets.size() - 1; i >= 1; i--) {
            for (int j = 0; j < buckets[i].size(); j++) {
                result.append(i, buckets[i][j]);
            }
        }
        return result;
    }
};

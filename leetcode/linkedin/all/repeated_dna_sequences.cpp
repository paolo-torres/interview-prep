// Given sequence, return all 10-letter substrings that occur more than once

// Maintain sliding window of size 10, insert into seen, if repeated, output

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> seen;
        unordered_set<string> repeat;
        
        for (int i = 0; i < n - 9; i++) {
            string curr = s.substr(i, 10);
            if (seen.find(curr) != seen.end()) {
                repeat.insert(curr);
            }
            seen.insert(curr);
        }
        
        vector<string> result;
        for (auto it = repeat.begin(); it != repeat.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }
};

/*
    Given users/times/sites, a pattern is a list of 3 sites, score is # of users that visited these sites in order
    Return the pattern with the largest score
    Ex. username = ["joe","joe","joe","james","james","james","james","mary","mary","mary"],
        timestamp = [1,2,3,4,5,6,7,8,9,10],
        website = ["home","about","career","home","cart","maps","home","home","about","career"]
        output -> ["home","about","career"], both joe and mary match to this pattern

    Collect users/times/sites into hash map, collect 3-sequences & counts, return max

    Time: O(n^3)
    Space: O(n)
*/

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // username -> {timestamp -> website}
        unordered_map<string, map<int, string>> userToDatas;
        // 3-sequence website -> # of occurrences of this pattern
        unordered_map<string, int> sequencesToCounts;
        int maxCount = 0;
        string result = "";
        
        // collect user data & store into userToData
        for (int i = 0; i < username.size(); i++) {
            userToDatas[username[i]][timestamp[i]] = website[i];
        }
        
        // collect three sequences & store into sequencesToCounts
        for (auto userToData : userToDatas) {
            unordered_set<string> threeSequences;
            
            for (auto it = begin(userToData.second); it != end(userToData.second); it++) {
                for (auto it1 = next(it); it1 != end(userToData.second); it1++) {
                    for (auto it2 = next(it1); it2 != end(userToData.second); it2++) {
                        threeSequences.insert(it->second + "#" + it1->second + "$" + it2->second);
                    }
                }
            }
            
            for (auto threeSequence : threeSequences) {
                sequencesToCounts[threeSequence]++;
            }
        }
        
        for (auto it = begin(sequencesToCounts); it != end(sequencesToCounts); it++) {
            if (it->second >= maxCount) {
                if (result == "" || it->second > maxCount) {
                    result = it->first;
                } else {
                    // if multiple sol'n, return lexicographically smallest
                    result = min(result, it->first);
                }
                maxCount = it->second;
            }
        }
        
        auto delimiter1 = result.find("#");
        auto delimiter2 = result.find("$");
        
        return {result.substr(0, delimiter1),
                result.substr(delimiter1 + 1, delimiter2 - delimiter1 - 1),
                result.substr(delimiter2 + 1)};
    }
};

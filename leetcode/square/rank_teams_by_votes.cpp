// Count rank of vote for each, sort wrt ranking system

// Time: O((m x n) log m) -> n = # votes, m = len(1st vote)
// Space: O(m^2)

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> count(26, vector<int>(27));
        for (int i = 0; i < votes[0].size(); i++) {
            char c = votes[0][i];
            count[c - 'A'][26] = c;
        }
        
        for (int i = 0; i < votes.size(); i++) {
            string vote = votes[i];
            for (int j = 0; j < vote.size(); j++) {
                count[vote[j] - 'A'][j]--;
            }
        }
        
        sort(count.begin(), count.end());
        
        string result = "";
        for (int i = 0; i < votes[0].size(); i++) {
            result += count[i][26];
        }
        return result;
    }
};

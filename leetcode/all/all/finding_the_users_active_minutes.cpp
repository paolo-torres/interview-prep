// Hash map: {user -> unique minutes}, count each of their unique minutes

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        
        for (int i = 0; i < logs.size(); i++) {
            m[logs[i][0]].insert(logs[i][1]);
        }
        
        vector<int> result(k);
        
        for (auto it = m.begin(); it != m.end(); it++) {
            int index = it->second.size() - 1;
            result[index]++;
        }
        
        return result;
    }
};

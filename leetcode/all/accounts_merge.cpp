// 1. Goal: group common emails together, sounds like union find
// 2. Group emails initially with themselves as the parent
// 3. Common emails should be joined by assigning the same parent
// Union find + disjoint-set: finds subset element is in, join subsets

// Time: O((m x n) log (m x n))
// Space: O(m x n)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> owners;
        unordered_map<string, string> parents;
        unordered_map<string, set<string>> unions;
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string owner = accounts[i][0];
                string email = accounts[i][j];
                owners[email] = owner;
                parents[email] = email;
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            string parent = find(accounts[i][1], parents);
            for (int j = 2; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                parents[find(email, parents)] = parent;
            }
        }
        
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                unions[find(email, parents)].insert(email);
            }
        }
        
        vector<vector<string>> result;
        
        for (auto it = unions.begin(); it != unions.end(); it++) {
            string name = it->first;
            set<string> emails = it->second;
            
            vector<string> curr(emails.begin(), emails.end());
            curr.insert(curr.begin(), owners[name]);
            
            result.push_back(curr);
        }
        
        return result;
    }
private:
    string find(string& email, unordered_map<string, string>& parents) {
        if (parents[email] != email) {
            parents[email] = find(parents[email], parents);
        }
        return parents[email];
    }
};

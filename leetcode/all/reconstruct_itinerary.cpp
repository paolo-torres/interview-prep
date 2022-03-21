class Solution {
private:
    unordered_map<string, multiset<string>> m;
    void visit(string airport, vector<string>& result) {
        while (!m[airport].empty()) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            visit(next, result);
        }
        result.push_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string> result;
        visit("JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
};

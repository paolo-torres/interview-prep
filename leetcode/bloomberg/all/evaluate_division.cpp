/*
    Given array of variable pairs, array of values where Ai / Bi = values[i], & queries, where queries[j] = [Cj, Dj]
    Return answers to all queries
    Ex. equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
        output -> [6.00000,0.50000,-1.00000,1.00000,-1.00000]

    Reformulate equations with graph, each var node, division relationship b/w vars edges

    Time: O(m x n)
    Space: O(n)
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m;
        
        for (int i = 0; i < equations.size(); i++) {
            string num = equations[i][0];
            string den = equations[i][1];
            double value = values[i];
            
            m[num][num] = 1.0;
            m[den][den] = 1.0;
            m[num][den] = value;
            m[den][num] = 1.0 / value;
        }
        
        unordered_set<string> visited;
        vector<double> result;
        
        for (int i = 0; i < queries.size(); i++) {
            string num = queries[i][0];
            string den = queries[i][1];
            visited.insert(num);
            result.push_back(dfs(num, den, m, visited));
            visited.clear();
        }
        
        return result;
    }
private:
    double dfs(string& start, string& end, unordered_map<string, unordered_map<string, double>>& m,
        unordered_set<string>& visited) {
        if (m.find(start) == m.end()) {
            return -1;
        }
        
        if (m[start].find(end) != m[start].end()) {
            return m[start][end];
        }
        
        for (auto it = m[start].begin(); it != m[start].end(); it++) {
            string variable = it->first;
            double value = it->second;
            
            if (visited.find(variable) != visited.end()) {
                continue;
            }
            visited.insert(variable);
            
            double curr = dfs(variable, end, m, visited);
            if (curr != -1) {
                m[start][end] = m[start][variable] * curr;
                return m[start][end];
            }
        }
        
        return -1;
    }
};

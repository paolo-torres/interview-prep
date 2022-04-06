// Time: O(V + E)
// Space: O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < prerequisites.size(); i++) {
            m[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        unordered_set<int> visited;
        
        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, m, visited)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visited) {
        if (visited.find(course) != visited.end()) {
            return false;
        }
        if (m[course].empty()) {
            return true;
        }
        visited.insert(course);
        for (int i = 0; i < m[course].size(); i++) {
            if (!dfs(m[course][i], m, visited)) {
                return false;
            }
        }
        m[course].clear();
        visited.erase(course);
        return true;
    }
};

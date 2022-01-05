// Time: O(V + E)
// Space: O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<int> degree(numCourses);
        vector<int> bfs;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            courses[b].push_back(a);
            degree[a]++;
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (degree[i] == 0) {
                bfs.push_back(i);
            }
        }
        
        for (int i = 0; i < bfs.size(); i++) {
            vector<int> prereqs = courses[bfs[i]];
            for (int j = 0; j < prereqs.size(); j++) {
                degree[prereqs[j]]--;
                if (degree[prereqs[j]] == 0) {
                    bfs.push_back(prereqs[j]);
                }
            }
        }
        
        if (bfs.size() == numCourses) {
            return true;
        }
        return false;
    }
};

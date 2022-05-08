/*
    Given ID of process want to kill, return list of IDs that will also be killed
    Each process only 1 parent, but may have multiple children, all get killed
    pid[i] is ID of ith process, ppid[i] is ID of ith process's parent process
    Ex. pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5 -> [5,10]

    Hash map + BFS, get all children of node to be killed, add to queue & proceed

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // {parent -> list of children}
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        
        queue<int> q;
        q.push(kill);
        
        vector<int> result;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            result.push_back(curr);
            
            for (int i = 0; i < m[curr].size(); i++) {
                int id = m[curr][i];
                q.push(id);
            }
        }
        
        return result;
    }
};

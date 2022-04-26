/*
    Given 2d int array where meetings[i] = [xi,yi,timei], person xi & yi meet at timei
    Person 0 has a secret & initially shares it w/ firstPerson at time 0
    Secret is then shared every time meeting takes place w/ person that has the secret
    Return a list of all the people that have the secret after all meetings take place

    Model problem as a graph, min heap to process by earliest time, detect overlaps

    Time: O(n log n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // create adjacency list between the people
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < meetings.size(); i++) {
            vector<int> meeting = meetings[i];
            adj[meeting[0]].push_back({meeting[1], meeting[2]});
            adj[meeting[1]].push_back({meeting[0], meeting[2]});
        }
        
        // use min heap sorted by earliest time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        // add both 0 and firstPerson since they know the secret
        pq.push({0, firstPerson});
        pq.push({0, 0});
        
        // if they've met & shared the secret to all possible people they could
        vector<bool> visited(n);
        
        while (!pq.empty()) {
            pair<int, int> curr = pq.top();
            pq.pop();
            
            int time = curr.first;
            int person = curr.second;
            
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            
            // iterate all meetings for this person & add potential new people
            vector<pair<int, int>> neighbors = adj[person];
            for (int i = 0; i < neighbors.size(); i++) {
                pair<int, int> neighbor = neighbors[i];
                if (!visited[neighbor.first] && time <= neighbor.second) {
                    pq.push({neighbor.second, neighbor.first});
                }
            }
        }
        
        // all visited people know the secret
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

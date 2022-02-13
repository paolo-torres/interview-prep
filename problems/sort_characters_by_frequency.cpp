// Time: O(n log n)
// Space: O(n)

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        priority_queue<pair<int, char>> pq;
        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->second, it->first});
        }
        
        string result;
        while (!pq.empty()) {
            int count = pq.top().first;
            char letter = pq.top().second;
            while (count > 0) {
                result += letter;
                count--;
            }
            pq.pop();
        }
        return result;
    }
};
